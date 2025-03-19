/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/

#include "test.h"

char *(*my_strstr)(const char *, const char *);

static void init(void)
{
    void *handle = dlopen("./libasm.so", RTLD_LAZY);

    if (!handle)
        write(2, "./libasm.so: Not found\n", 23);
    else
        my_strstr = dlsym(handle, "strstr");
}

Test(strstr_test, substring_present)
{
    init();
    char *str = "Hello, World!";
    char *substr = "World";

    char *result = my_strstr(str, substr);

    cr_assert(result != NULL);
}

Test(strstr_test, substring_not_present)
{
    init();
    char *str = "Hello, World!";
    char *substr = "Goodbye";

    char *result = my_strstr(str, substr);

    cr_assert(result == NULL);
}