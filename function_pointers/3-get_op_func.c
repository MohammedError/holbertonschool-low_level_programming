#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform
 * the operation asked by the user
 * @s: The operator passed as argument
 *
 * Return: Pointer to the function corresponding to the operator.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	/* Loop to find the operator, respects constraints */
	while (ops[i].op != NULL)
	{
		/* Check first char and ensure operator is only 1 char long */
		if (ops[i].op[0] == s[0] && s[1] == '\0')
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
