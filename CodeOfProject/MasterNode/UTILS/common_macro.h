
#ifndef _COMMON_MACRO_H
#define _COMMON_MACRO_H

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLEAR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOGGLE_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define READ_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)


#endif
