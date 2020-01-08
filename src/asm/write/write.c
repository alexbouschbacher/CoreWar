/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int write_reg(char *arg)
{
	int reg;
	char *cpy = arg;

	arg++;
	reg = my_getnbr(arg);
	if (reg >= 0 && reg <= 15)
		return (reg);
	else {
		my_putstr("Invalid register: ");
		my_putstr(cpy);
		my_putstr("\n");
		exit (84);
	}
}

int write_dir(char *arg, int size, int pos, func_t *funcs)
{
	int nbr;
	char *cpy = arg;

	arg++;
	if (*arg == ':') {
		arg++;
		nbr = find_pos(arg, funcs, pos);
	} else {
		if ((nbr = my_getnbr(arg)) == -84) {
			my_putstr("Invalid argument: ");
			my_putstr(cpy);
			my_putstr("\n");
		}
	}
	nbr = rev_int(nbr);
	if (size == 2)
		nbr = nbr >> 16;
	return (nbr);
}

int write_indir(char *arg, int pos, func_t *funcs)
{
	int nbr;
	char *cpy = arg;

	if (*arg == ':') {
		arg++;
		nbr = find_pos(arg, funcs, pos);
	} else {
		if ((nbr = my_getnbr(arg)) == -84) {
			my_putstr("Invalid argument: ");
			my_putstr(cpy);
			my_putstr("\n");
		}
	}
	nbr = rev_int(nbr);
	return (nbr);
}

void write_code(int info[3], char *arg, int pos, func_t *funcs)
{
	int wr;

	if (info[0] == 1)
		wr = write_reg(arg);
	else if (info[0] == 2)
		wr = write_dir(arg, info[1], pos, funcs);
	else
		wr = write_indir(arg, pos, funcs);
	write(info[2], &wr, info[1]);
}

void write_args(char **tab, int *pos, int fd, func_t *funcs)
{
	int arg = 0;
	char **args;
	int res;
	int info[3] = {0, 0, 0};

	info[2] = fd;
	pos[0]--;
	while (pos[1] < len_tab(tab)) {
		args = my_str_to_word_array(tab[pos[1]], ',');
		for (int j = 0; args[j] != NULL; j++) {
			info[0] = get_type(args[j]);
			res = op_tab[pos[0]].type[arg];
			arg = arg + 1;
			info[1] = find_arg(info[0], res, pos[0]);
			write_code(info, args[j], pos[2], funcs);
		}
		pos[1]++;
	}
}
