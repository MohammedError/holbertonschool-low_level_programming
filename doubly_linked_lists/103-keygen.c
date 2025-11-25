#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates valid key for crackme5
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, len;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char key[7];
	int tmp;

	if (argc != 2)
		return (1);

	len = strlen(argv[1]);

	/* Key char 1: Length based */
	tmp = (len ^ 59) & 63;
	key[0] = l[tmp];

	/* Key char 2: Sum of chars */
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += argv[1][i];
	tmp = (tmp ^ 79) & 63;
	key[1] = l[tmp];

	/* Key char 3: Product of chars */
	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= argv[1][i];
	tmp = (tmp ^ 85) & 63;
	key[2] = l[tmp];

	/* Key char 4: Max char based */
	tmp = 0;
	for (i = 0; i < len; i++)
		if (argv[1][i] > tmp)
			tmp = argv[1][i];
	srand(tmp ^ 14);
	tmp = rand() & 63;
	key[3] = l[tmp];

	/* Key char 5: Sum of squares */
	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += (argv[1][i] * argv[1][i]);
	tmp = (tmp ^ 239) & 63;
	key[4] = l[tmp];

	/* Key char 6: Random loop based on first char */
	for (i = 0; i < argv[1][0]; i++)
		rand();
	tmp = rand() & 63;
	key[5] = l[tmp];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
