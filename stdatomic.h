#pragma once

#include <stdbool.h>

#define ATOMIC_VAR_INIT(value)      (value)
#define atomic_init(object, value)  (void)(*(object) = (value))

typedef volatile int    atomic_int;

#ifdef __GNUC__
#define atomic_store(object, desired)   (void)( *(volatile typeof(*(object)) *)(object) = (desired) )
#define atomic_load(object)             *(volatile typeof(*(object)) *)(object)
#else
#define atomic_store(object, desired)   (void)(*(object) = (desired))
#define atomic_load(object)             *(object)
#endif

#define ATOMIC_FLAG_INIT { 0 }

typedef struct atomic_flag { bool _Value; } atomic_flag;

extern bool atomic_flag_test_and_set(volatile atomic_flag *flag);
extern void atomic_flag_clear(volatile atomic_flag *flag);

extern int atomic_fetch_add(atomic_int *object, int operand);
extern int atomic_fetch_sub(atomic_int *object, int operand);
extern int atomic_fetch_or(atomic_int *object, int operand);
extern int atomic_fetch_xor(atomic_int *object, int operand);
extern int atomic_fetch_and(atomic_int *object, int operand);

extern int atomic_exchange(atomic_int *object, int desired);

extern bool atomic_compare_exchange_strong(atomic_int *object, int *expected, int desired);
extern bool atomic_compare_exchange_weak(atomic_int *object, int *expected, int desired);

