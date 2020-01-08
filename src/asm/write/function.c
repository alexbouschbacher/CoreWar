/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

func_t set_func(char *name, int pos)
{
	func_t func;
	int len = my_strlen(name) - 1;

	func.name = my_strncpy(name, len);
	func.pos = pos;
	return (func);
}

void fill_funcs(func_t *funcs, int src)
{
	char *line;
	int i = 0;
	int pos;

	for (char **tab; (line = get_next_line(src)) != NULL; free_tab(tab)) {
		line = clear_str(line);
		printf("f[%s]\n", line);
		tab = my_str_to_word_array(line, '#');
		if (len_tab(tab) == 2 || len_tab(tab) == 0)
			continue;
		free (line);
		line = my_strncpy(tab[0], my_strlen(tab[0]));
		free_tab(tab);
		tab = my_str_to_word_array(line, ' ');
		if (len_tab(tab) == 0)
			continue;
		if (tab[0][my_strlen(tab[0]) - 1] == ':')
			funcs[i++] = set_func(tab[0], pos);
		pos += line_size(tab, len_tab(tab));
		free(line);
	}
}

int how_func(int src)
{
	char *line;
	int i = 0;

	for (char **tab; (line = get_next_line(src)) != NULL; free_tab(tab)) {
		printf("w[%s]\n", line);
		tab = my_str_to_word_array(line, '#');
		if (len_tab(tab) == 2 || len_tab(tab) == 0)
			continue;
		free (line);
		line = my_strcpy(tab[0]);
		free_tab(tab);
		tab = my_str_to_word_array(line, ' ');
		if (len_tab(tab) == 0)
			continue;
		if (tab[0][my_strlen(tab[0]) - 1] == ':')
			i++;
		free(line);
	}
	return (i);
}

func_t *find_funcs(int fd, int begin)
{
	int len = how_func(fd);
	func_t *funcs = malloc (sizeof(func_t) * (len + 1));

	lseek(fd, begin, SEEK_SET);
	fill_funcs(funcs, fd);
	return (funcs);
}
