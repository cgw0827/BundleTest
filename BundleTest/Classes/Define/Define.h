//
//  Define.h
//  SMSDX
//
//  Created by cwa leiting on 13-2-21.
//
//

#ifndef __SMSDX__Define__
#define __SMSDX__Define__
#include <string>
#define NO false
#define YES true

#define nil NULL
#define BOOL bool
typedef unsigned int ALuint;
typedef float CGFloat;
typedef int NSInteger;
typedef unsigned int NSUInteger;
typedef unsigned int uint32_t;

typedef double CFTimeInterval;
const int LEN=1;
const std::string FILE_NAME[LEN]={"FarmEventTalkWord"};
#define CCLocalizedStringFromTable(key, tbl, comment) \
CCBundle::mainBundle()->localizedStringForKey(key,"",tbl)
#endif /* defined(__SMSDX__Define__) */
