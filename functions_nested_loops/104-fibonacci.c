#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long f1 = 1, f2 = 2;
	unsigned long f1_h, f1_l, f2_h, f2_l;
	unsigned long limit = 1000000000; /* 1 billion for splitting */

	printf("%lu, %lu", f1, f2);

	for (i = 3; i <= 92; i++)
	{
		unsigned long next = f1 + f2;

		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}

	/* Split the last calculated numbers to handle overflow */
	f1_h = f1 / limit;
	f1_l = f1 % limit;
	f2_h = f2 / limit;
	f2_l = f2 % limit;

	for (i = 93; i <= 98; i++)
	{
		unsigned long next_h, next_l;

		next_l = f1_l + f2_l;
		next_h = f1_h + f2_h + (next_l / limit);
		next_l %= limit;

		printf(", %lu%09lu", next_h, next_l);

		f1_h = f2_h;
		f1_l = f2_l;
		f2_h = next_h;
		f2_l = next_l;
	}

	printf("\n");
	return (0);
}
