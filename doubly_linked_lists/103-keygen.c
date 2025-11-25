#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i, sum = 0, diff, q, r;

	if (argc != 2)
		return (1);

	/* Calculate sum of username characters */
	for (i = 0; argv[1][i]; i++)
		sum += argv[1][i];

	/* The target checksum for crackme5 is 2772 (0xAD4) */
	diff = 2772 - sum;

	/* * We divide the difference by 80 ('P') to generate base characters.
	 * We adjust if the remainder is not a printable character (< 33).
	 */
	q = diff / 80;
	r = diff % 80;

	while (r < 33 && q > 0)
	{
		r += 80;
		q--;
	}

	/* Print the base characters */
	for (i = 0; i < q; i++)
		putchar(80);

	/* Print the remainder */
	putchar(r);

	return (0);
}
