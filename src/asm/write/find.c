/*
** EPITECH PROJECT, 2018
** step1
** File description:
** 2.1
*/

#include "main.h"

int find_action(char *act)
{
	for (int i = 0; op_tab[i].code != 0; i++)
		if (my_strcmp(op_tab[i].mnemonique, act) == 0)
			return (i);
	my_putstr("Unknown function\n");
	exit (84);
}

int get_type(char *arg)
{
	int type = 0;
	char *cpy = arg;

	if (arg[0] == 'r') {
		arg++;
		type = T_REG;
	} else if (arg[0] == '%') {
		arg++;
		type = T_DIR;
	} else
		type = T_IND;
	if (is_number(arg) == 1 && *arg != ':') {
		my_putstr("Invalid argument: ");
		my_putstr(cpy);
		my_putstr("\n");
		exit (84);
	}
	return (type);
}

int get_code(int type)
{
	if (type == 1)
		return (1);
	else if (type == 2)
		return (2);
	else
		return (3);
}
