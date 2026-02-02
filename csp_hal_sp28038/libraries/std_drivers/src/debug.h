//###########################################################################
//
// FILE:   debug.h
//
// TITLE:  Assert definition macro for debug.
//
//###########################################################################

#ifndef DEBUG_H
#define DEBUG_H


//*****************************************************************************
//
// The ASSERT macro, which does the actual assertion checking.  Typically, this
// will be for procedure arguments.
//
//*****************************************************************************
#ifdef _DEBUG
#ifdef USE_FULL_ASSERT
// Reports the name of the source file and the source line number 
// where the ASSERT error has occurred.
void assert_failed(uint8_t* file, uint32_t line)
{
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
}
//
// The ASSERT macro is used for function's parameters check.
//
#define ASSERT(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
#else
#define ASSERT(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */
#else
#define ASSERT(expr)
#endif /* _DEBUG */

#endif // DEBUG_H
