#include "queue.h"

Queue* init_queue(size_t size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    // int x = 10;
    queue->list = createList(NULL, size);
    queue->size = 0;
    return queue;
}

void enqueue(void* value, Queue* queue){
    add(value, queue->list);
    queue->size = queue->size + 1;
}

Node* dequeue(Queue* queue){
    Node* head = queue->list->head;
    Node* returnedValue = (Node*)malloc(sizeof(Node));
    returnedValue->value = malloc(sizeof(queue->item_size));

    memcpy(returnedValue->value, head->value, sizeof(queue->item_size));
    // printf("%i\n", *(struct*)returnedValue->value);

    removeBegin(queue->list);
    queue->size -= 1;
    return returnedValue;  
}

int isEmpty(Queue* queue){
    return queue->size == 0;
}

