#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: pointer to hashtable
 * @key: key to search
 * Return: the value associated
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int idx;
	char *nkey;
	hash_node_t *temp;

	if (ht == NULL)
		return (NULL);
	nkey = strdup(key);
	idx = key_index((unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp)
	{
		if (strcmp(temp->key, nkey) == 0)
			break;
		temp = temp->next;
	}
	free(nkey);

	if (temp == NULL)
		return (NULL);

	return (temp->value);
}
