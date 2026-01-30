#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 5
int hashTable[TABLE_SIZE];
void initialize() 
{
    int i;
	for (i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) 
{
    return key % TABLE_SIZE;
}

void insert(int key) 
{
    int index = hash(key);
    while (hashTable[index] != -1) 
	{
        index = (index + 1) % TABLE_SIZE;  // Linear probing
    }
    hashTable[index] = key;
}

int search(int key) 
{
    int index = hash(key),i, probeIndex ;
    for ( i = 0; i < TABLE_SIZE; i++) {
        probeIndex = (index + i) % TABLE_SIZE;
        if (hashTable[probeIndex] == key)
            return probeIndex;
        if (hashTable[probeIndex] == -1)
            return -1;
    }
    return -1;
}

void display() 
{
    int i;
	for (i = 0; i < TABLE_SIZE; i++) 
	{
        if (hashTable[i] != -1)
            printf("Slot %d: %d\n", i, hashTable[i]);
        else
            printf("Slot %d: Empty\n", i);
    }
}

int main() 
{
    initialize();
    int choice, key;
    while (1) 
	{
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = search(key);
                if (pos == -1)
                    printf("Key not found.\n");
                else
                    printf("Key found at position %d.\n", pos);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

