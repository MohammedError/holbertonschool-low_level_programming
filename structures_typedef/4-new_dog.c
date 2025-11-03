#include "dog.h"
#include <stdlib.h> /* For malloc */

/**
 * _strlen - finds the length of a string
 * @s: The string
 * Return: The length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copies a string
 * @dest: The destination buffer
 * @src: The source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner
 * Return: Pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len_name, len_owner;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	len_name = _strlen(name);
	dog->name = malloc(sizeof(char) * (len_name + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	_strcpy(dog->name, name);

	len_owner = _strlen(owner);
	dog->owner = malloc(sizeof(char) * (len_owner + 1));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	_strcpy(dog->owner, owner);

	dog->age = age;

	return (dog);
}
