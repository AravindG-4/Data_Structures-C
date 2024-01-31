#include <stdio.h>
#include <stdlib.h>

struct KeyValuePair {
    int key;
    int value;
    struct KeyValuePair* next;
};

#define TABLE_SIZE 10
struct KeyValuePair* hashTable[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);

    struct KeyValuePair* newPair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
    newPair->key = key;
    newPair->value = value;
    newPair->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newPair;
    } else {
        newPair->next = hashTable[index];
        hashTable[index] = newPair;
    }
}

int get(int key) {
    int index = hash(key);
    struct KeyValuePair* current = hashTable[index];

    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; 
}

int main() {
    insert(5, 42);
    insert(10, 99);
    insert(15, 7);

    printf("Value for key 5: %d\n", get(5));
    printf("Value for key 10: %d\n", get(10));
    printf("Value for key 15: %d\n", get(15));

    for (int i = 0; i < TABLE_SIZE; ++i) {
        struct KeyValuePair* current = hashTable[i];
        while (current != NULL) {
            struct KeyValuePair* next = current->next;
            free(current);
            current = next;
        }
        hashTable[i] = NULL;
    }

    return 0;
}