/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int args_line(char **tab, int i, int len)
{
	int arg = 1;
	char **args;
	int type;
	int code;
	int key = 0;

	for (; i < len; i++) {
		args = my_str_to_word_array(tab[i], ',');
		for (int j = 0; args[j]; j++) {
			type = get_type(args[j]);
			code = get_code(type);
			key = (key << 2) | code;
			arg++;
		}
	}
	while (arg <= 4) {
		key = key << 2;
		arg++;
	}
	return (key);
}

int find_pos(char *arg, func_t *funcs, int pos)
{
	int len;
	int i = 0;
	unsigned int res;

	for (len = 0; funcs[len].name != NULL; len++);
	for (; funcs[i].name; i++) {
		if (my_strcmp(arg, funcs[i].name) == 0)
			break;
	}
	if (i == len) {
		my_putstr("Invalid reference: ");
		my_putstr(arg);
		my_putstr(" not found\n");
		exit (84);
	}
	res = funcs[i].pos - pos;
	return (res);
}


void set_line(char **tab, int fd, func_t *funcs, int size)
{
	int args;
	static int s = 0;
	int *pos = my_calloc_int (3);

	pos[2] = s;
	if (tab[pos[1]][my_strlen(tab[pos[1]]) - 1] == ':')
		pos[1]++;
	if (tab[pos[1]] == NULL)
		return;
	pos[0] = find_action(tab[pos[1]++]) + 1;
	write(fd, &pos[0], 1);
	if (pos[0] != 1 && pos[0] != 9 && pos[0] != 12 && pos[0] != 15) {
		args = args_line(tab, pos[1], len_tab(tab));
		write(fd, &args, 1);
	}
	write_args(tab, pos, fd, funcs);
	s += size;
	free(pos);
}

void fill_prog(int src, int dest, func_t *funcs)
{
	char *line;

	for (char **tab; (line = get_next_line(src)) != NULL; free_tab(tab)) {
		printf("fp[%s]\n", line);
		tab = my_str_to_word_array(clear_str(line), '#');
		if (len_tab(tab) == 2 || len_tab(tab) == 0 || line[0] == '#')
			continue;
		free (line);
		line = my_strcpy(tab[0]);
		free_tab(tab);
		tab = my_str_to_word_array(line, ' ');
		if (len_tab(tab) == 0)
			continue;
		set_line(tab, dest, funcs, line_size(tab, len_tab(tab)));
		free(line);
	}
}
