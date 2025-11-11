#include "3-calc.h"
#include <stdio.h>  /* For printf */
#include <stdlib.h> /* For atoi, exit */

/**
 * main - performs simple operations
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, 98/99/100 on failure.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *op;
	int (*func_ptr)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	func_ptr = get_op_func(op);

	if (func_ptr == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = func_ptr(num1, num2);
	printf("%d\n", result);

	return (0);
}
