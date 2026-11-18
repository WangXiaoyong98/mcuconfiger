import importlib.util
import tempfile
import unittest
import zipfile
from pathlib import Path
from unittest.mock import patch

from utils.sys import SysUtils

from proto import sio_package_description_pb2 as description_pb
from proto import sio_package_install_pb2 as install_pb
from proto import sio_package_list_pb2 as list_pb
from proto import sio_package_uninstall_pb2 as uninstall_pb


class PackageSocketTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        server = Path(__file__).resolve().parents[2] / "csp-server.py"
        spec = importlib.util.spec_from_file_location("csp_test_server", server)
        cls.server = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cls.server)

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        patcher = patch.object(
            SysUtils, "packages_folder", return_value=str(self.root / "packages")
        )
        patcher.start()
        self.addCleanup(patcher.stop)
        self.client = self.server.socketio.test_client(self.server.app)
        self.addCleanup(self.client.disconnect)

    def invoke(self, event, response_type, message=None):
        args = () if message is None else (message.SerializeToString(),)
        data = self.client.emit(event, *args, callback=True)
        self.assertIsInstance(data, bytes)
        legacy = self.client.get_received()
        self.assertTrue(
            any(
                item["name"] == event.removeprefix("sio/") + ".result"
                for item in legacy
            )
        )
        return response_type.FromString(data)

    def test_install_list_description_uninstall(self):
        source = (
            Path(__file__).resolve().parents[4]
            / "csp_hal_sp28038"
            / "csp_hal_sp28038.csppdsc"
        )
        archive = self.root / "test.csppack"
        with zipfile.ZipFile(archive, "w") as package:
            package.write(source, source.name)
            package.writestr("README.md", "Test package")
        installed = self.invoke(
            "sio/package/install",
            install_pb.SioPackageInstallResponse,
            install_pb.SioPackageInstallRequest(path=str(archive)),
        )
        self.assertTrue(installed.success, installed.error)
        info = installed.description
        packages = self.invoke("sio/package/list", list_pb.SioPackageListResponse)
        self.assertTrue(packages.success, packages.error)
        self.assertIn(info.name, packages.packages[info.type])
        description = self.invoke(
            "sio/package/description",
            description_pb.SioPackageDescriptionResponse,
            description_pb.SioPackageDescriptionRequest(
                type=info.type, name=info.name, version=info.version
            ),
        )
        self.assertTrue(description.success, description.error)
        self.assertEqual(description.description.name, info.name)
        removed = self.invoke(
            "sio/package/uninstall",
            uninstall_pb.SioPackageUninstallResponse,
            uninstall_pb.SioPackageUninstallRequest(
                type=info.type, name=info.name, version=info.version
            ),
        )
        self.assertTrue(removed.success, removed.error)
        packages = self.invoke("sio/package/list", list_pb.SioPackageListResponse)
        self.assertFalse(packages.packages)

    def test_install_from_directory(self):
        source = (
            Path(__file__).resolve().parents[4]
            / "csp_hal_sp28038"
            / "csp_hal_sp28038.csppdsc"
        )
        folder = self.root / "source"
        folder.mkdir()
        (folder / source.name).write_bytes(source.read_bytes())
        (folder / "README.md").write_text("Directory package", encoding="utf-8")
        installed = self.invoke(
            "sio/package/install",
            install_pb.SioPackageInstallResponse,
            install_pb.SioPackageInstallRequest(path=str(folder)),
        )
        self.assertTrue(installed.success, installed.error)
        copied = list((self.root / "packages").rglob("README.md"))
        self.assertEqual(len(copied), 1)
        self.assertEqual(copied[0].read_text(encoding="utf-8"), "Directory package")

    def test_invalid_package_returns_failure_acknowledgement(self):
        result = self.invoke(
            "sio/package/install",
            install_pb.SioPackageInstallResponse,
            install_pb.SioPackageInstallRequest(
                path=str(self.root / "missing.csppack")
            ),
        )
        self.assertFalse(result.success)
        self.assertTrue(result.error)

    def test_missing_description_returns_failure_acknowledgement(self):
        result = self.invoke(
            "sio/package/description",
            description_pb.SioPackageDescriptionResponse,
            description_pb.SioPackageDescriptionRequest(
                type="hal", name="missing", version="1.0"
            ),
        )
        self.assertFalse(result.success)
        self.assertTrue(result.error)
