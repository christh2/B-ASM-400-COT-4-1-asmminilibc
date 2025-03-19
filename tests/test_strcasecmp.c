/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/

#include "test.h"

int (*my_strcasecmp)(const char *, const char *);

static void init(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else
        my_strcasecmp = dlsym(handle, "strcasecmp");
}

Test(strcasecmp_test, equal_strings)
{
    init();
    char *str1 = "Hello, World!";
    char *str2 = "Hello, World!";

    int result = my_strcasecmp(str1, str2);

    cr_assert(result == 0);
}

Test(strcasecmp_test, case_insensitive_comparison)
{
    init();
    char *str1 = "Hello, World!";
    char *str2 = "hello, world!";

    int result = my_strcasecmp(str1, str2);

    cr_assert(result == 0);
}

Test(strcasecmp_test, different_strings)
{
    init();
    char *str1 = "Hello, World!";
    char *str2 = "Goodbye, World!";

    int result = my_strcasecmp(str1, str2);

    cr_assert(result != 0);
}