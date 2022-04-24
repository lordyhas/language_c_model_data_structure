#include "util.h"
#include "static_linked_list.h"


typedef LinkedList Stack;


// access
T valueOfStack(Stack);
Bool isStackEmpty(Stack);
Bool isStackFull(Stack);
Bool isStackOverflow(Stack);


/// modif
void createStack(Stack);
void push(Stack, T);
void pop(Stack);