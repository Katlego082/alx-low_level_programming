#include "hash_tables.h"
/**
 * hash_djb2 - algoritm for
 * @str: string is used for generate hash value
 * Return: table of hash
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hashe;
	int c;

	hashe = 5381;
	while ((c = *str++))
	{
		hashe = hashe * 33 + c;
	}
	return (hashe);
}
