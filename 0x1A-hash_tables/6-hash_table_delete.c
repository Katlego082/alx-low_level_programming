#include <stdlib.h>

// Define a structure for a key-value pair
typedef struct {
    char* key;
    char* value;
} KeyValuePair;

// Define a structure for a hash table
typedef struct {
    int size;           // Number of buckets
    KeyValuePair** table; // Array of buckets
} hash_table_t;

// Function to delete a key-value pair
void delete_key_value_pair(KeyValuePair* kv) {
    if (kv) {
        free(kv->key);
        free(kv->value);
        free(kv);
    }
}

// Function to delete a hash table
void hash_table_delete(hash_table_t *ht) {
    if (ht) {
        for (int i = 0; i < ht->size; i++) {
            KeyValuePair* current = ht->table[i];
            while (current) {
                KeyValuePair* next = current->next;
                delete_key_value_pair(current);
                current = next;
            }
        }

        free(ht->table);
        free(ht);
    }
}

int main() {
    // Create a hash table
    hash_table_t* ht = (hash_table_t*)malloc(sizeof(hash_table_t));
    ht->size = 10;
    ht->table = (KeyValuePair**)malloc(sizeof(KeyValuePair*) * ht->size);

    // Populate the hash table with data

    // Delete the hash table and its contents
    hash_table_delete(ht);

    return 0;
}
