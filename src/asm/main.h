/*
** EPITECH PROJECT, 2018
** Project corewar
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#define READ_SIZE 1
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include "op.h"

	typedef struct func_s {
		char *name;
		int pos;
	} func_t;

	char *clear_str(char *);
	char *get_next_line(int);
	char **my_str_to_word_array(char *, char);
	int my_strlen(char *);
	char *my_strcpy(char *);
	char *my_strncpy(char *, int);
	void my_strcpy2(char *, char *);
	int my_strcmp(char *, char *);
	int my_strncmp(char *, char *, int);
	void my_putstr(char *);
	void free_tab(char **);
	int len_tab(char **);
	int is_number(char *);
	int rev_int(int);
	char *get_name(char *str);
	char *get_arg(char *);
	char *get_info(char *, int);
	int set_header(header_t *, int);
	int find_action(char *);
	int get_type(char *);
	int find_arg(int, int, int);
	int check_args(char **, int, int, int *);
	int args_size(char **, int, int, int);
	int line_size(char **, int);
	int find_size(int);
	func_t set_func(char *, int);
	void fill_funcs(func_t *, int);
	int how_func(int);
	func_t *find_funcs(int, int);
	int get_code(int);
	int write_reg(char *arg);
	int write_dir(char *, int, int, func_t *);
	int write_indir(char *, int, func_t *);
	void write_code(int[3], char *, int, func_t *);
	void write_args(char **, int *, int, func_t *);
	int args_line(char **, int, int);
	int find_pos(char *, func_t *, int);
	void set_line(char **, int, func_t *, int);
	void fill_prog(int, int, func_t *);
	int *my_calloc_int(int);
	int my_getnbr(char const *);
	int error_header(int);
	void error_set_line(char **, func_t *, int);
	void error_fill_prog(int, func_t *);
	void error_write_code(int[2], char *, int, func_t *);
	void error_write_args(char **, int *, func_t *);
#endif
