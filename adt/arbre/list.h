#include "util.h"
#include "tree_rec.h"
//#define N 15
#define NIL -1
#define TAILLEMAX 10
typedef int Cursor;
typedef Node T;


typedef struct cell
{
    T value;
    Cursor next;
    
}Cell, *CellPtr;

typedef struct listSC
{
    int taille;
    Cell list[TAILLEMAX];
    Cursor first;
    Cursor key;
    Cursor firstFree;
}LinkedList_ , *LinkedList;


void createList(LinkedList);
CellPtr createCell(T);
void moveKeyToStart(LinkedList);
void moveKeyToNext(LinkedList);
Cursor getKey(LinkedList);
void setKey(LinkedList, Cursor);
T getCurrentValue(LinkedList); 
Cursor getFreeCell(LinkedList); // first free
void freeCellAfter(LinkedList, Cursor); //  cursop is a new position
void freeCellBefore(LinkedList, Cursor); 
void insertAfter(LinkedList, T);
void insertBefore(LinkedList , T);
Bool isFullList(LinkedList);
void deleteBefore(LinkedList);
void deleteAfter(LinkedList);
Bool isEmptyList(LinkedList);
Bool isEndOfList(LinkedList);
int length(LinkedList);




