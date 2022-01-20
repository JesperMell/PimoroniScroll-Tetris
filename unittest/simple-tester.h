#ifndef _SIMPLE_TESTER_H_
#define _SIMPLE_TESTER_H_

#define TEST(name, a,b) (if((uint32_t)a != (uint32_t)b) {\
    printf("Failed to test %s: expected: %d, actual %d", name, a, b));

#endif 
