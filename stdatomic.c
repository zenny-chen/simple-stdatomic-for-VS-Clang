#ifdef _MSC_VER

#include <stdio.h>
#include <intrin.h>

#include "stdatomic.h"

int8_t zenny_atomic_fetch_add8(volatile atomic_schar* object, int8_t operand)
{
    int8_t expected = *object;
    int8_t desired;
    bool success;

    do
    {
        desired = expected + operand;
    } while ((success = zenny_atomic_compare_exchange8(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int16_t zenny_atomic_fetch_add16(volatile atomic_short* object, int16_t operand)
{
    int16_t expected = *object;
    int16_t desired;
    bool success;

    do
    {
        desired = expected + operand;
    } while ((success = zenny_atomic_compare_exchange16(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int32_t zenny_atomic_fetch_add32(volatile atomic_long* object, int32_t operand)
{
    int32_t expected = *object;
    int32_t desired;
    bool success;

    do
    {
        desired = expected + operand;
    }
    while ((success = zenny_atomic_compare_exchange32(object, &expected, desired)),
        (success? (void)0 : _mm_pause()), 
        !success);

    return expected;
}

int64_t zenny_atomic_fetch_add64(volatile atomic_llong* object, int64_t operand)
{
    int64_t expected = *object;
    int64_t desired;
    bool success;

    do
    {
        desired = expected + operand;
    } while ((success = zenny_atomic_compare_exchange64(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int8_t zenny_atomic_fetch_sub8(volatile atomic_schar* object, int8_t operand)
{
    int8_t expected = *object;
    int8_t desired;
    bool success;

    do
    {
        desired = expected - operand;
    } while ((success = zenny_atomic_compare_exchange8(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int16_t zenny_atomic_fetch_sub16(volatile atomic_short* object, int16_t operand)
{
    int16_t expected = *object;
    int16_t desired;
    bool success;

    do
    {
        desired = expected - operand;
    } while ((success = zenny_atomic_compare_exchange16(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int32_t zenny_atomic_fetch_sub32(volatile atomic_long* object, int32_t operand)
{
    int32_t expected = *object;
    int32_t desired;
    bool success;

    do
    {
        desired = expected - operand;
    } while ((success = zenny_atomic_compare_exchange32(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int64_t zenny_atomic_fetch_sub64(volatile atomic_llong* object, int64_t operand)
{
    int64_t expected = *object;
    int64_t desired;
    bool success;

    do
    {
        desired = expected - operand;
    } while ((success = zenny_atomic_compare_exchange64(object, &expected, desired)),
        (success ? (void)0 : _mm_pause()),
        !success);

    return expected;
}

int8_t zenny_atomic_fetch_or8(volatile atomic_schar* object, int8_t operand)
{
    return _InterlockedOr8(object, operand);
}

int16_t zenny_atomic_fetch_or16(volatile atomic_short* object, int16_t operand)
{
    return _InterlockedOr16(object, operand);
}

int32_t zenny_atomic_fetch_or32(volatile atomic_long* object, int32_t operand)
{
    return _InterlockedOr(object, operand);
}

int64_t zenny_atomic_fetch_or64(volatile atomic_llong* object, int64_t operand)
{
    return _InterlockedOr64(object, operand);
}

int8_t zenny_atomic_fetch_xor8(volatile atomic_schar* object, int8_t operand)
{
    return _InterlockedXor8(object, operand);
}

int16_t zenny_atomic_fetch_xor16(volatile atomic_short* object, int16_t operand)
{
    return _InterlockedXor16(object, operand);
}

int32_t zenny_atomic_fetch_xor32(volatile atomic_long* object, int32_t operand)
{
    return _InterlockedXor(object, operand);
}

int64_t zenny_atomic_fetch_xor64(volatile atomic_llong* object, int64_t operand)
{
    return _InterlockedXor64(object, operand);
}

int atomic_fetch_and(volatile atomic_int *object, int operand)
{
    return _InterlockedAnd((long volatile *)object, operand);
}

int atomic_exchange(volatile atomic_int *object, int desired)
{
    return _InterlockedExchange((volatile long*)object, desired);
}

bool zenny_atomic_compare_exchange8(volatile atomic_schar* object, int8_t* expected, int8_t desired)
{
    int8_t comparand = *expected;
    const int8_t dstValue = _InterlockedCompareExchange8(object, desired, comparand);
    bool success = dstValue == comparand;
    if (!success)
        *expected = dstValue;

    return success;
}

bool zenny_atomic_compare_exchange16(volatile atomic_short* object, int16_t* expected, int16_t desired)
{
    int16_t comparand = *expected;
    const int16_t dstValue = _InterlockedCompareExchange16(object, desired, comparand);
    bool success = dstValue == comparand;
    if (!success)
        * expected = dstValue;

    return success;
}

bool zenny_atomic_compare_exchange32(volatile atomic_long* object, int32_t* expected, int32_t desired)
{
    int32_t comparand = *expected;
    int32_t dstValue = _InterlockedCompareExchange(object, desired, comparand);
    bool success = dstValue == comparand;
    if (!success)
        *expected = dstValue;

    return success;
}

bool zenny_atomic_compare_exchange64(volatile atomic_llong* object, int64_t* expected, int64_t desired)
{
    int64_t comparand = *expected;
    int64_t dstValue = _InterlockedCompareExchange64(object, desired, comparand);
    bool success = dstValue == comparand;
    if (!success)
        *expected = dstValue;

    return success;
}

bool atomic_flag_test_and_set(volatile atomic_flag *flag)
{
    return _InterlockedExchange8((volatile char*)flag, 1) == 1;
}

void atomic_flag_clear(volatile atomic_flag *flag)
{
    _InterlockedExchange8((volatile char*)flag, 0);
}

#endif

