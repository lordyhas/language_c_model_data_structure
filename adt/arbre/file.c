#include "file.h"


Queue createQueue(void){
    return createDLList();
}
void enqueue(Queue F, T v){
    insertAtStart(F, v);
}

void dequeue(Queue F){
    deleteAtEnd(F);
}

T valueOfQueue(Queue F){
    moveKeyToEnd(F);
    return getCurrentValue(F);
}

Bool isQueueEmpty(Queue F){
    return isListEmpty(F);
}

Bool isQueueFull(Queue F){

}

Bool queueExist(Queue F){
    if(F!=NULL) return True;
    return False;
}
void destroyQueue(Queue F){
    for (int i = 0; i < length(F)-1; i++)
        dequeue(F);
    
    free(F);
    F = NULL;
    
}

