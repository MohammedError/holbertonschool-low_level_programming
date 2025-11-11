#include "function_pointers.h"
#include <stddef.h> /* For size_t */

/**
 * array_iterator - executes a function on each element of an array
 * @array: The array
 * @size: The size of the array
 * @action: Pointer to the function to execute
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
