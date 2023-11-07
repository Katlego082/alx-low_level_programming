#include "hash_tables.h"
/**
 * hash_table_print - function to print a hash table
 * @ht: pointer to the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	char *divi;

	if (ht == NULL)
		return;
	printf("{");
	divi = "";
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			printf("%s'%s': '%s'", divi, temp->key, temp->value);
			divi = ", ";
			temp = temp->next;
		}
	}
	printf("}\n");
}
