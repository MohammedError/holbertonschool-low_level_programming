#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	password[i] = 2772 - sum;
	password[i + 1] = '\0';

	printf("%s", password);

	return (0);
}
