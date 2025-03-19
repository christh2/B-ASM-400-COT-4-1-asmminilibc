/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/

#include "test.h"

char *(*my_strchr)(const char *, int);

static void init(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else
        my_strchr = dlsym(handle, "strchr");
}

Test(strchr_test, character_present)
{
    init();
    char *str = "Hello, World!";
    int ch = 'o';

    char *result = my_strchr(str, ch);

    cr_assert(result != NULL);
    cr_assert(*result == ch);
}

Test(strchr_test, character_not_present)
{
    init();
    char *str = "Hello, World!";
    int ch = 'z';

    char *result = my_strchr(str, ch);

    cr_assert(result == NULL);
}