#include "util.h"

typedef char T; 

typedef struct dcell
{
    T value;
    struct dcell * prev;
    struct dcell * next;
    
} DCell_ , *DCell, *Cursor;

//typedef DCell Cursor;


typedef struct Dlist
{
    int size;  
    Cursor first;
    Cursor key;
    Cursor last;
    
} DLinkedList_, *DLL;


DCell createCell(T v);
DLL createDLList(void);
int length(DLL);
T getCurrentValue(DLL);
Cursor getKey(DLL);
void setKey(DLL, Cursor);

Cursor getFirst(DLL);
Cursor getLast(DLL);

void insertAtEnd(DLL, T);
void insertAtStart(DLL, T);
void insertAfterKey(DLL , T);

void deleteAtEnd(DLL);
void deleteAfterKey(DLL);
void deleteAtStart(DLL);
void moveKeyToStart(DLL);
void moveKeyToEnd(DLL);
void moveKeyToNext(DLL);
void moveKeyToPrev(DLL);

Bool isListEmpty(DLL);
Bool isEndOfList(DLL);








