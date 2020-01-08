/*
** EPITECH PROJECT, 2018
** Project corewar Testing
** File description:
** Unit Testing Project corewar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "main.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(corewar, Return_Value_Test)
{
	cr_assert_eq("Function to test()", "Int Output..");
}

// Test(corewar, Stdout_Value_Test, .init = main_redirect_stdout)
// {
//	Function to test();
//	cr_assert_stdout_eq_str("Str Output..");
// }