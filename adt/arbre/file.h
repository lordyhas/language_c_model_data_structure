#include "util.h"
#include "dlist.h"


typedef DLL Queue;

Queue createQueue(void);
void enqueue(Queue, T);
void dequeue(Queue);
T valueOfQueue(Queue);
Bool isQueueEmpty(Queue);
Bool isQueueFull(Queue);
Bool queueExist(Queue);
void destroyQueue(Queue);


