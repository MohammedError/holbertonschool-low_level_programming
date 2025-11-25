#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a key for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char password[100];
	int i, sum, n;

	if (argc != 2)
	{
		printf("Usage: ./keygen5 username\n");
		return (1);
	}

	srand(time(NULL));
	sum = 0;
	for (i = 0; argv[1][i]; i++)
		sum += argv[1][i];

	i = 0;
	while (sum < 2772 - 122)
	{
		n = (rand() % (122 - 97 + 1)) + 97;
		password[i] = n;
		sum += n;
		i++;
	}

	n = 2772 - sum;
	password[i] = n;
	password[i + 1] = '\0';

	printf("%s", password);

	return (0);
}
