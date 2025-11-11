#include <stdio.h>  /* For printf */
#include <stdlib.h> /* For atoi, exit */

/**
 * main - prints the opcodes of its own main function
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, 1 or 2 on error.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *main_opcodes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	/*
	 * Cast the function pointer 'main' to a pointer to unsigned char.
	 * This allows us to read the individual bytes (opcodes)
	 * of the main function's machine code.
	 */
	main_opcodes = (unsigned char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		/* Print the byte in lowercase hex, padded to 2 digits */
		printf("%02x", main_opcodes[i]);

		/* Print a space, but not after the last byte */
		if (i < num_bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
