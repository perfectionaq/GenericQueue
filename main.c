#include "queue.h"
#include <unistd.h>
#include <pthread.h>

#define slice 4

typedef struct process{
    unsigned int burst_time;
    char label;
} process;

//args is the process that is going to run
void* run(void* args){
    process* p = (process*)args;
    printf("process %c has began execution\n", p->label);
    int processedSlice;
    
    if(slice > p->burst_time){
        sleep(p->burst_time);
        p->burst_time = 0;
    } else{
        sleep(slice);
        p->burst_time = p->burst_time - slice;
    }
    printf("process %c is ending with remainint time slice = %i\n\n", p->label ,p->burst_time);

    return p;
}

int main(void){
    Queue* queue = init_queue(sizeof(process)); // initialize a queue of processes 
    process p1 = {24, 'A'};
    process p2 = {3, 'B'};
    process p3 = {3, 'C'};
    process p4 = {1, 'D'};
    process p5 = {9, 'E'};
    process p6 = {5, 'F'};
    process p7 = {7, 'G'};
    process p8 = {5, 'H'};
    process p9 = {20, 'I'};
    process p10 = {15, 'J'};

    enqueue(&p1, queue);
    enqueue(&p2, queue);
    enqueue(&p3, queue);
    // enqueue(&p4, queue);
    // enqueue(&p5, queue);
    // enqueue(&p6, queue);
    // enqueue(&p7, queue);
    // enqueue(&p8, queue);
    // enqueue(&p9, queue);
    // enqueue(&p10, queue);

    // printf("%c\n", ((process*)(dequeue(queue)->value))->label);
    pthread_t p1t;

    while(!isEmpty(queue)){
        process* temp = dequeue(queue)->value;
        pthread_create(&p1t, NULL, run, temp);
        pthread_join(p1t, (void**)&temp);

        if(temp->burst_time > 0)
            enqueue(temp, queue); 
    }

    return 0;
}