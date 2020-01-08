/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int find_arg(int type, int res, int func)
{
	if (type == 1 && (res == 1 || res == 3 || res == 5 || res == 7))
		return (1);
	if (type == 2 && (res == 2 || res == 3 || res == 6 || res == 7)) {
		if ((func >= 8 && func <= 11) || func == 14)
			return (2);
		return (4);
	}
	if (type == 4 && (res == 4 || res == 5 || res == 6 || res == 7))
		return (2);
	return (0);
}

int check_args(char **args, int len, int func, int *arg)
{
	int type;
	int res;
	int s;
	int size = 0;

	for (int i = 0; i < len; i++) {
		type = get_type(args[i]);
		res = op_tab[func].type[*arg];
		*arg = *arg + 1;
		s = find_arg(type, res, func);
		if (s != 0) {
			size += s;
			continue;
		}
		my_putstr("Invalid argument type\n");
		exit (84);
	}
	return (size);
}

int args_size(char **tab, int func, int i, int len)
{
	int arg = 0;
	char **args;
	int size = 0;

	while (i < len) {
		args = my_str_to_word_array(tab[i], ',');
		size += check_args(args, len_tab(args), func, &arg);
		i++;
	}
	if (arg != op_tab[func].nbr_args) {
		my_putstr("Too few arguments for this function\n");
		exit (84);
	}
	return (size);
}

int line_size(char **tab, int len_tab)
{
	int size = 0;
	int act = 0;
	int i = 0;

	if (tab[i][my_strlen(tab[i]) - 1] == ':')
		i++;
	if (tab[i] == NULL)
		return (0);
	act = find_action(tab[i++]);
	if (act != 0 && act != 8 && act != 11 && act != 14)
		size++;
	size++;
	size += args_size(tab, act, i, len_tab);
	return (size);
}

int find_size(int src)
{
	int size = 0;
	char *line;

	for (char **tab; (line = get_next_line(src)) != NULL; free_tab(tab)) {
		printf("fs[%s]\n", line);
		tab = my_str_to_word_array(clear_str(line), '#');
		if (len_tab(tab) == 2 || len_tab(tab) == 0)
			continue;
		free (line);
		line = my_strncpy(tab[0], my_strlen(tab[0]));
		free_tab(tab);
		tab = my_str_to_word_array(line, ' ');
		if (len_tab(tab) == 0)
			continue;
		size += line_size(tab, len_tab(tab));
	}
	return (size);
}
