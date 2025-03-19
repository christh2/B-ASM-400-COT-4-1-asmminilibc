/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/


#include "test.h"

int (*my_strlen)(const char *);
static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strlen = dlsym(handle, "strlen");
}

Test(basiq, basiq) {
    init();
    char *str = "well";
    cr_assert(strlen(str) == my_strlen(str));
}

Test(vide, vide) {
    init();
    char *str = "";
    cr_assert(strlen(str) == my_strlen(str));
}

Test(espace, espace) {
    init();
    char *str = "\t\n";
    cr_assert(strlen(str) == my_strlen(str));
}

Test(mix, mix) {
    init();
    char *str = "hello\nthere\thi\n";
    cr_assert(strlen(str) == my_strlen(str));
}