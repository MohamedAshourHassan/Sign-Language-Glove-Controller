#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#ifndef LOGIC_HIGH
#define LOGIC_HIGH        (1u)
#endif

#ifndef LOGIC_LOW
#define LOGIC_LOW         (0u)
#endif


#ifndef ENABLE
#define ENABLE            (1u)
#endif

#ifndef DISABLE
#define DISABLE         (0u)
#endif
#define NULL_PTR    ((void *)0)
#define ARRAY_ELEMENTS       3

#define  OK      (0u)
#define  NOTOK   (1u)
typedef unsigned char           uint8;
typedef signed char           sint8;          /*        -128 .. +127             */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef signed short          sint16;         /*      -32768 .. +32767           */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef signed long           sint32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32;
typedef double                float64;


#endif




