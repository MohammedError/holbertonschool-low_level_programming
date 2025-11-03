#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: The width of the grid
 * @height: The height of the grid
 *
 * Return: Pointer to the 2D array, or NULL on failure
 * or if width/height is 0 or negative.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w, i;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		grid[h] = malloc(sizeof(int) * width);

		if (grid[h] == NULL)
		{
			/* Free previously allocated memory on failure */
			for (i = 0; i < h; i++)
				free(grid[i]);
			free(grid);
			return (NULL);
		}

		/* Initialize to 0 */
		for (w = 0; w < width; w++)
			grid[h][w] = 0;
	}

	return (grid);
}
