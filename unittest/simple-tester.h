#ifndef _SIMPLE_TESTER_H_
#define _SIMPLE_TESTER_H_

#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

#define TEST(name, a,b)              \
  ({                                 \
    if((uint32_t)a != (uint32_t)b) { \
      printf("Failed %s: expected: %d, actual %d", name, a, b); \
  });\
  };

#endif 
