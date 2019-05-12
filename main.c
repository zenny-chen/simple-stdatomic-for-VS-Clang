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
    uint8_t value8 = atomic_fetch_add(&atomChar, -121);
    printf("value8 = %u, atomChar = %u\n", value8, atomic_load(&atomChar));

    value8 = atomic_fetch_sub(&atomChar, 128);
    printf("value8 = %u, atomChar = %u\n", value8, atomic_load(&atomChar));

    value8 = atomic_fetch_or(&atomChar, 0x80);
    printf("value8 = 0x%02x, atomChar = 0x%02x\n", value8, atomic_load(&atomChar));

    value8 = atomic_fetch_xor(&atomChar, 0x88);
    printf("value8 = 0x%02x, atomChar = 0x%02x\n", value8, atomic_load(&atomChar));

    volatile atomic_char16_t alignas(16) atomU16;
    atomic_init(&atomU16, u'לר');
    char16_t valueU16 = atomic_fetch_add(&atomU16, 30000);
    printf("\nvalueU16 is: %u, atomU16 = %u\n", valueU16, atomic_load(&atomU16));
}

