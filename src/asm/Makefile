##
## EPITECH PROJECT, 2018
## Project corewar
## File description:
## Build corewar binary.
##

MAIN_SRC	=	main.c

SRC	=	gnl.c	\
		op.c	\
		clear_str.c	\
		my_str_to_word_array.c	\
		strlib.c	\
		strcpy.c	\
		utils.c	\
		write/header.c	\
		write/find.c	\
		write/size.c	\
		write/function.c	\
		write/write.c	\
		write/fill_prog.c	\
		errors/header.c	\
		errors/write.c	\
		errors/fill_prog.c	\

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	+=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/ -lm -g3

LDFLAGS	=	-lcriterion

NAME	=	asm

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f unit-tests
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete
	find . -name "coverage*" -type f -delete

re: fclean all

tests_run:	CFLAGS += --coverage

tests_run:	$(UT_OBJ)
		gcc -o unit-tests $(UT_OBJ) $(LDFLAGS) $(CFLAGS)
		./unit-tests

cov:	tests_run
	gcovr -r . --html -o coverage.html --html-details -e ".*tests/.*"

.PHONY: all clean fclean re
