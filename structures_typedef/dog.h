#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic info
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Defines a structure to hold a dog's info
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/* Prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
