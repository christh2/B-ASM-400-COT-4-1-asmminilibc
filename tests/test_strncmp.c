/*
** EPITECH PROJECT, 2024
** asm
** File description:
** asm
*/


#include "test.h"

int (*my_strncmp)(const char *, const char *, int n);
static void init(void)
{
	void *handle = dlopen("./libasm.so", RTLD_LAZY);

	if (!handle)
		write(2, "./libasm.so: Not found\n", 23);
	else
		my_strncmp = dlsym(handle, "strncmp");
}

Test(egal, egal) {
    init();
    char *s1 = "bomb";
    char *s2 = "bombon";
    int nb = 4;

    cr_assert(my_strncmp(s1, s2, nb) == 0);
}

Test(egal_special, egal_special) {
    init();
    char *s1 = "ab\ncde";
    char *s2 = "ab\ndef";
    int nb = 3;

    cr_assert(my_strncmp(s1, s2, nb) == 0);
}

Test(moin, moin) {
    init();
    char *s1 = "abcd";
    char *s2 = "abdc";
    int nb = 3;

    cr_assert(my_strncmp(s1, s2, nb) < 0);
}

Test(superieur, superieur) {
    init();
    char *s1 = "abcd";
    char *s2 = "abab";
    int nb = 3;

    cr_assert(my_strncmp(s1, s2, nb) > 0);
}

Test(rien, rien) {
    init();
    char *s1 = "abcd";
    char *s2 = "abab";
    int nb = 0;

    cr_assert(my_strncmp(s1, s2, nb) == 0);
}
