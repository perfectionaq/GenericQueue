#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    void* value;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
    Node* tail;
    size_t nodeSize;
} LinkedList;

void add(void* value, LinkedList* list);
void append(void* value, LinkedList* list);
void removeBegin(LinkedList* list);
void removeEnd(LinkedList* list);

LinkedList* createList(void* headValue, size_t nodeSize);
void add(void* value, LinkedList* list);
void printList(LinkedList* list, void(*fptr)(Node*));
void printInts(Node* node);