#include "dog.h"
#include <stdlib.h> /* For free */

/**
 * free_dog - frees a dog
 * @d: Pointer to the dog to free
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
