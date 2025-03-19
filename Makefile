##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## christ
##
 
SRC =   strlen.asm  \
		strncmp.asm	\
		strcmp.asm	\
		strchr.asm	\
		strrchr.asm	\
		memset.asm	\
		memcpy.asm	\
		strstr.asm	\
		memmove.asm	\
		strcasecmp.asm

TEST_SRC=	tests/test_strlen.c	\
			tests/test_strncmp.c	\
			tests/test_strcmp.c	\
			tests/test_strchr.c	\
			tests/test_memmove.c	\
			tests/test_strcasecmp.c	\
			tests/test_memcpy.c	\
			tests/test_strstr.c

OBJ =   $(SRC:.asm=.o)

TEST	=	$(TEST_SRC:.c=.o)
 
NAME    =   libasm.so
 
all: $(SRC) $(NAME)
                 
$(NAME): $(OBJ)
	ld -shared -o $(NAME) $(OBJ)
                                              
%.o: %.asm
	nasm -f elf64 -o $*.o $*.asm
 
clean:
	rm -f *~
	rm -f *.o
	rm -f $(TEST)
	rm -rf *.gcda
	rm -rf *.gcno
 
fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
 
re: fclean all

tests_run:
	gcc -o unit_tests $(TEST_SRC) -I ./include/ --coverage -lcriterion -ldl
	./unit_tests
	gcovr --exclude ./tests/ --branches
	gcovr --exclude ./tests/