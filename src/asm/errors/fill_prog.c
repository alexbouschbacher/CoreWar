/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

void error_set_line(char **tab, func_t *funcs, int size)
{
	int args = 0;
	static int s = 0;
	int *pos = my_calloc_int (3);

	pos[2] = s;
	if (tab[pos[1]][my_strlen(tab[pos[1]]) - 1] == ':')
		pos[1]++;
	if (tab[pos[1]] == NULL)
		return;
	pos[0] = find_action(tab[pos[1]++]) + 1;
	if (pos[0] != 1 && pos[0] != 9 && pos[0] != 12 && pos[0] != 15)
		args = args_line(tab, pos[1], len_tab(tab));
	(void) args;
	error_write_args(tab, pos, funcs);
	s += size;
	free(pos);
}

void error_fill_prog(int src, func_t *funcs)
{
	char *line;

	for (char **tab; (line = get_next_line(src)) != NULL; free_tab(tab)) {
		line = clear_str(line);
		printf("ef[%s]\n", line);
		tab = my_str_to_word_array(line, '#');
		if (len_tab(tab) == 2 || len_tab(tab) == 0 || line[0] == '#')
			continue;
		free (line);
		line = my_strcpy(tab[0]);
		free_tab(tab);
		tab = my_str_to_word_array(line, ' ');
		if (len_tab(tab) == 0)
			continue;
		error_set_line(tab, funcs, line_size(tab, len_tab(tab)));
		free(line);
	}
}
