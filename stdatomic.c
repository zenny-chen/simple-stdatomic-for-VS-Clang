#include <stdio.h>
#include <intrin.h>

#include "stdatomic.h"

int atomic_fetch_add(atomic_int *object, int operand)
{
    int expected = *object;
    int desired;
    bool success;

    do
    {
        desired = expected + operand;
    }
    while ((success = atomic_compare_exchange_strong(object, &expected, desired)), 
        (success? (void)0 : _mm_pause()), 
        !success);

    return expected;
}

int atomic_fetch_sub(atomic_int *object, int operand)
{
    int expected = *object;
    int desired;
    bool success;

    do
    {
        desired = expected - operand;
    } while ((success = atomic_compare_exchange_strong(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int atomic_fetch_or(atomic_int *object, int operand)
{
    return _InterlockedOr((long volatile *)object, operand);
}

int atomic_fetch_xor(atomic_int *object, int operand)
{
    return _InterlockedXor((long volatile *)object, operand);
}

int atomic_fetch_and(atomic_int *object, int operand)
{
    return _InterlockedAnd((long volatile *)object, operand);
}

int atomic_exchange(atomic_int *object, int desired)
{
    return _InterlockedExchange((volatile long*)object, desired);
}

bool atomic_compare_exchange_strong(atomic_int *object, int *expected, int desired)
{
    int comparand = *expected;
    int dstValue = _InterlockedCompareExchange((volatile long*)object, desired, comparand);
    bool success = dstValue == comparand;
    if (!success)
        *expected = dstValue;

    return success;
}

bool atomic_compare_exchange_weak(atomic_int *object, int *expected, int desired)
{
    return atomic_compare_exchange_strong(object, expected, desired);
}

bool atomic_flag_test_and_set(volatile atomic_flag *flag)
{
    return _InterlockedExchange8((volatile char*)flag, 1) == 1;
}

void atomic_flag_clear(volatile atomic_flag *flag)
{
    _InterlockedExchange8((volatile char*)flag, 0);
}
