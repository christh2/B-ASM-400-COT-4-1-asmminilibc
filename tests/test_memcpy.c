/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/

#include "test.h"

void *(*my_memcpy)(void *, const void *, size_t);

static void init(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else
        my_memcpy = dlsym(handle, "memcpy");
}


Test(memcpy_test, copy_array)
{
    init();
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];

    void *result = my_memcpy(dest, src, sizeof(src));

    for (int i = 0; i < 5; i++) {
        cr_assert(dest[i] == src[i]);
    }
}