#ifndef PLATFORM_H
#define PLATFORM_H

/* Provide a PRINTF macro that abstracts printf dependency */
#ifdef HOST
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else

/* For MSP432 cross-compile we still map PRINTF to printf provided by newlib */

/* declare printf to avoid including stdio on embedded
 headers */

int printf(const char *fmt, ...);
#define PRINTF(...) printf(__VA_ARGS__)
#endif

#endif /* PLATFORM_H */
