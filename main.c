#include <stdio.h>
#include <stdbool.h>

#include "stdatomic.h"

#define var    __auto_type

static atomic_int atom = ATOMIC_VAR_INIT(100);

int main(void)
{
    var a = 100;

    atomic_int at;
    atomic_init(&at, a);

    atomic_store(&at, 100);

    printf("The answer is: %d\n", atomic_load(&at) + atomic_load(&atom));

    a = atomic_fetch_add(&at, 10);
    a = atomic_load(&at);
    atomic_store(&at, 200);
    bool flag = atomic_compare_exchange_strong(&at, &a, -1);
    if (!flag)
        flag = atomic_compare_exchange_weak(&at, &a, -1);

    printf("a = %d\n", a + flag);

    getchar();
}

