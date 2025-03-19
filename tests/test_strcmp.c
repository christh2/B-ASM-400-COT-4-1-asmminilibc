/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/


#include "test.h"

int (*my_strcmp)(const char *, const char *);
static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strcmp = dlsym(handle, "strcmp");
}

Test(egall, egall) {
    init();
    char *s1 = "bomb";
    char *s2 = "bomb";

    cr_assert(my_strcmp(s1, s2) == 0);
}

Test(egall_special, egall_special) {
    init();
    char *s1 = "bomb\n";
    char *s2 = "bomb\n";

    cr_assert(my_strcmp(s1, s2) == 0);
}

Test(lesser, lesser) {
    init();
    char *s1 = "ab";
    char *s2 = "cd";

    cr_assert(my_strcmp(s1, s2) < 0);
}

Test(lesser_mul, lesser_mul) {
    init();
    char *s1 = "aba";
    char *s2 = "abb";

    cr_assert(my_strcmp(s1, s2) < 0);
}
