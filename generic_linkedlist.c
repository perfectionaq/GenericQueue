#include "generic_linkedlist.h"


LinkedList* createList(void* headValue, size_t nodeSize){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->nodeSize = nodeSize;

    if(headValue == NULL){
        list->head = NULL;
        list->tail = NULL;
        return list;
    }

    Node* node = (Node*)malloc(sizeof(Node));
    
    node->value = malloc(nodeSize);
    memcpy(node->value, headValue, nodeSize);
    node->next = NULL;

    list->head = node;
    list->tail = node;
    
    return list;
}

void add(void* value, LinkedList* list){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = malloc(list->nodeSize);
    memcpy(newNode->value, value, list->nodeSize);

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
        list->head->next = NULL;
        list->tail->next = NULL;
        return;
    }

    list->tail->next = newNode;
    list->tail = list->tail->next;
    newNode->next = NULL;
}

void printList(LinkedList* list, void(*fptr)(Node*)){
    Node* temp = list->head;
    int x = 0;
    while(temp != 0){
        fptr(temp);
        temp = temp->next;
    }
}

void printInts(Node* node){
    printf("%i\n", *(int*)node->value);
}

void removeBegin(LinkedList* list){
    Node* tempHead = list->head;

    list->head = list->head->next;
    tempHead->next = NULL;
    free(tempHead->value);
    tempHead->value = NULL;
    free(tempHead);
    tempHead = NULL;
}

void removeEnd(LinkedList* list){
    Node* tempTail = list->tail;
    Node* temp = list->head;

    while(temp->next != tempTail){
        temp = temp->next;
    }

    list->tail = temp;
    list->tail->next = NULL;

    free(tempTail->value);  
    tempTail->value = NULL;
    free(tempTail);
    tempTail = NULL;
}