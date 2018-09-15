#include "generic_linkedlist.h"

typedef struct Queue{
    LinkedList* list;
    size_t item_size;
    unsigned int size;
} Queue;


Queue* init_queue(size_t size);
void enqueue(void* value, Queue* queue);
Node* dequeue(Queue* list);
int isEmpty(Queue* queue);