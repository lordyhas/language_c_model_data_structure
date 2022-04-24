#include "util.h"
#define NIL -1

typedef int Cursor;
typedef char T;
typedef struct heap
{
    Cursor length;
    Cursor sizeMax;
    T *tab;
} *Heap ;

Heap createHeap();
void addHeap(Heap,T);
void deleteRoot(Heap);
void destroyHeap(Heap);
Bool isHeapEmpty(Heap);

T valueOfHeap(Heap);
int sizeOfHeap(Heap);
T getValue(Heap, Cursor);

void reorganizationASC(Heap);
void reorganizationDESC(Heap);
void setValue(Heap, T, Cursor);
Cursor childRight(Cursor);
Cursor childLeft(Cursor);
Cursor father(Cursor);