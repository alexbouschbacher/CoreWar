/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

void error_write_code(int info[2], char *arg, int pos, func_t *funcs)
{
	int wr;

	if (info[0] == 1)
		wr = write_reg(arg);
	else if (info[0] == 2)
		wr = write_dir(arg, info[1], pos, funcs);
	else
		wr = write_indir(arg, pos, funcs);
	(void) wr;
}

void error_write_args(char **tab, int *pos, func_t *funcs)
{
	int arg = 0;
	char **args;
	int res;
	int info[2] = {0, 0};

	pos[0]--;
	while (pos[1] < len_tab(tab)) {
		args = my_str_to_word_array(tab[pos[1]], ',');
		for (int j = 0; args[j] != NULL; j++) {
			info[0] = get_type(args[j]);
			res = op_tab[pos[0]].type[arg];
			arg = arg + 1;
			info[1] = find_arg(info[0], res, pos[0]);
			error_write_code(info, args[j], pos[0], funcs);
		}
		pos[1]++;
	}
}
