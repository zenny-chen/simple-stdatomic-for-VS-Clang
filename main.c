#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <uchar.h>
#include <assert.h>
#include "stdatomic.h"
#include "stdalign.h"
#include "threads.h"

static thread_local int sss = 0;

int main(void)
{
    int a = alignof(long double);
    printf("alignment of long double is: %d\n", a);

    static_assert(alignof(long double) > 4, "Nope!");

    volatile atomic_uchar alignas(16) atomChar;
    atomic_init(&atomChar, 120);

    uint8_t value8 = atomic_fetch_add_explicit(&atomChar, -121, memory_order_relaxed);
    printf("value8 = %u, atomChar = %u\n", value8, atomic_load_explicit(&atomChar, memory_order_relaxed));

    value8 = atomic_fetch_sub_explicit(&atomChar, 128, memory_order_relaxed);
    printf("value8 = %u, atomChar = %u\n", value8, atomic_load(&atomChar));

    value8 = atomic_fetch_or_explicit(&atomChar, 0x80, memory_order_relaxed);
    printf("value8 = 0x%02x, atomChar = 0x%02x\n", value8, atomic_load(&atomChar));

    value8 = atomic_fetch_xor_explicit(&atomChar, 0x88, memory_order_relaxed);
    printf("value8 = 0x%02x, atomChar = 0x%02x\n", value8, atomic_load(&atomChar));

    atomic_store_explicit(&atomChar, 0x55, memory_order_relaxed);

    value8 = atomic_fetch_and_explicit(&atomChar, 0xa1, memory_order_relaxed);
    printf("value8 = 0x%02x, atomChar = 0x%02x\n", value8, atomic_load(&atomChar));

    value8 = atomic_exchange_explicit(&atomChar, 255, memory_order_relaxed);
    printf("value8 = %u, atomChar = %u\n", value8, atomic_load(&atomChar));

    value8 = atomic_load_explicit(&atomChar, memory_order_seq_cst);
    value8--;
    if (!atomic_compare_exchange_weak_explicit(&atomChar, &value8, 100, memory_order_acq_rel, memory_order_acquire))
        printf("Failed! value8 = %u\n", value8);

    if (atomic_compare_exchange_weak_explicit(&atomChar, &value8, 100, memory_order_acq_rel, memory_order_acquire))
        printf("Succeeded! atomChar = %u\n", atomChar);

    volatile atomic_char16_t alignas(16) atomU16;
    atomic_init(&atomU16, u'禅');

    char16_t valueU16 = atomic_fetch_add(&atomU16, 30000);
    printf("\nvalueU16 is: %u, atomU16 = %u\n", valueU16, atomic_load(&atomU16));

    valueU16 = atomic_fetch_sub(&atomU16, 61000);
    printf("valueU16 = %u, atomU16 = %u\n", valueU16, atomic_load(&atomU16));

    valueU16 = atomic_fetch_or(&atomU16, 0x80);
    printf("valueU16 = 0x%02x, atomU16 = 0x%02x\n", valueU16, atomic_load(&atomU16));

    valueU16 = atomic_fetch_xor(&atomU16, 0x88);
    printf("valueU16 = 0x%02x, atomU16 = 0x%02x\n", valueU16, atomic_load(&atomU16));

    atomic_store(&atomU16, 0xaa55);

    valueU16 = atomic_fetch_and(&atomU16, 0x55a1);
    printf("valueU16 = 0x%04x, atomU16 = 0x%04x\n", valueU16, atomic_load(&atomU16));

    valueU16 = atomic_exchange(&atomU16, 65535);
    printf("valueU16 = %u, atomU16 = %u\n", valueU16, atomic_load(&atomU16));

    valueU16 = atomic_load(&atomU16);
    valueU16--;
    if (!atomic_compare_exchange_weak(&atomU16, &valueU16, 1000))
        printf("Failed! valueU16 = %u\n", valueU16);

    if (atomic_compare_exchange_weak(&atomU16, &valueU16, 1000))
        printf("Succeeded! atomU16 = %u\n", atomU16);
}

