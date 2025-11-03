#include <stdio.h>

/**
 * main - prints the number of arguments passed to it
 * @argc: The argument count
 * @argv: The argument vector (unused)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	(void)argv; /* Ignore argv */
	printf("%d\n", argc - 1);
	return (0);
}
