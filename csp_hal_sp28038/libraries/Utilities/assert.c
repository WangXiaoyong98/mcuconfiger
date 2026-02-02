/*
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "debug_console.h"

#ifndef NDEBUG
#if (defined(__CC_ARM)) || (defined(__ARMCC_VERSION)) || (defined(__ICCARM__))
void __aeabi_assert(const char *failedExpr, const char *file, int line)
{
#ifdef SDK_DEBUGCONSOLE
    (void)PRINTF("ASSERT ERROR \" %s \": file \"%s\" Line \"%d\" \n", failedExpr, file, line);
#endif

    for (;;)
    {
        __BKPT(0);
    }
}
#elif (defined(__GNUC__))
void __assert_func(const char *file, int line, const char *func, const char *failedExpr)
{
    (void)PRINTF("ASSERT ERROR \" %s \": file \"%s\" Line \"%d\" function name \"%s\" \n", failedExpr, file, line,
                 func);
    for (;;)
    {
        __BKPT(0);
    }
}
#else  /* (defined(__CC_ARM) || (defined(__ICCARM__)) || (defined(__ARMCC_VERSION)) */

#if (defined(__DSC__) && defined(__CW__))

void __msl_assertion_failed(char const *failedExpr, char const *file, char const *func, int line)
{
    PRINTF("\r\nASSERT ERROR\r\n");
    PRINTF("  File      : %s\r\n", file);
    PRINTF("  Function  : %s\r\n", func); /*compiler not support func name yet*/
    PRINTF("  Line      : %u\r\n", (uint32_t)line);
    PRINTF("  failedExpr: %s\r\n", failedExpr);
    asm(DEBUGHLT);
}

#endif /* (defined(__DSC__) && defined (__CW__)) */

#endif /* (defined(__CC_ARM) || (defined(__ICCARM__)) || (defined(__ARMCC_VERSION)) */
#endif /* NDEBUG */
