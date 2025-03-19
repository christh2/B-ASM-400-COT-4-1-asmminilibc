/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/

#include "test.h"

void *(*my_memmove)(void *, const void *, size_t);

static void init(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else
        my_memmove = dlsym(handle, "memmove");
}

Test(memmove_test, overlapping_buffers)
{
    init();
    char src[] = "Hello, World!";
    char dest[] = "*************";

    void *result = my_memmove(dest, src, 13);

    cr_assert(result == dest);
    cr_assert_str_eq(dest, "Hello, World!");
}

Test(memmove_test, non_overlapping_buffers)
{
    init();
    char src[] = "Hello, World!";
    char dest[20];

    void *result = my_memmove(dest, src, 7);

    cr_assert(result == dest);
    cr_assert_str_eq(dest, "Hello, ");
}