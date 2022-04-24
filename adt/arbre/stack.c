#include "util.h"
#include "stack.h"


// access

Bool isStackEmpty(Stack s){
    return isEmptyList(s);
}
Bool isStackFull(Stack s){
    return isFullList(s);
}

T valueOfStack(Stack s){
    moveKeyToStart(s);
    return getCurrentValue(s);
}

/// modif
void createStack(Stack s){
    createList((LinkedList) s);
}

void push(Stack s, T v){
    insertBefore(s, v);
    //moveKeyToStart(s);
    //insert();
    
}

void pop(Stack s){
    deleteBefore(s);
}