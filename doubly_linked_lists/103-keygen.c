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
	int i = 0, sum = 0, n;
	char password[100];

	if (argc != 2)
		return (1);

	for (n = 0; argv[1][n]; n++)
		sum += argv[1][n];

	/* Target sum is 2772. Use only safe chars ('z' = 122) to fill */
	while (sum < 2772 - 122)
	{
		password[i++] = 122;
		sum += 122;
	}

	/* Calculate the last needed value */
	n = 2772 - sum;

	/* * If the remainder 'n' is not a safe alphanumeric char,
	 * reduce the previous char (which is 'z') to make 'n' safe.
	 * Safe ranges: 48-57 (0-9), 65-90 (A-Z), 97-122 (a-z)
	 */
	while ((n < 48) || (n > 57 && n < 65) || (n > 90 && n < 97))
	{
		if (i > 0) /* Backtrack to previous 'z' */
		{
			password[--i] -= 1; /* Reduce 'z' to 'y' etc */
			sum -= 1;
		}
		n = 2772 - sum; /* Re-calculate remainder */
		i++; /* Move index back */
	}

	password[i++] = n;
	password[i] = '\0';

	printf("%s", password);

	return (0);
}
