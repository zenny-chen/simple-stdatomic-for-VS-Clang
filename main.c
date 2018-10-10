#include <stdio.h>
#include <stdbool.h>
#include "stdatomic.h"

static atomic_int atom = ATOMIC_VAR_INIT(100);

int main(void)
{
    int a = 100;
    atomic_int at;

    atomic_init(&at, a);
    atomic_store(&at, 100);
    printf("The answer is: %d\n", atomic_load(&at) + atomic_load(&atom));

    a = atomic_fetch_add(&at, 10);
    a = atomic_load(&at);
    atomic_store(&at, 200);

    bool value = atomic_compare_exchange_strong(&at, &a, -1);

    if (!value)
        value = atomic_compare_exchange_weak(&at, &a, -1);

    printf("a = %d\n", a + value);

    atomic_flag flag = ATOMIC_FLAG_INIT;
    bool res = atomic_flag_test_and_set(&flag);
    res = atomic_flag_test_and_set(&flag);

    atomic_flag_clear(&flag);

    res = atomic_flag_test_and_set(&flag);

    printf("The bool size is: %zu", sizeof(bool));

    getchar();
}
