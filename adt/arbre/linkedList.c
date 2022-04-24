#include "list.h"

/*CellList allocationCell(void){
    CellList cellList = (CellList) malloc(N*sizeof(Cell));
    return cellList;
}*/

//List allocationList(void){}

void createList(LinkedList listSC){
    
    int i ;

    for (i = 0 ; i < TAILLEMAX-1; i++)
        listSC->list[i].next = i+1;
    listSC->list[i].next = NIL;
       
    listSC->first = NIL;
    listSC->key = NIL;
    listSC->firstFree = 0;
    listSC->taille = 0; 
    //printf("\n createList(1) : %d", listSC->firstFree);

}

CellPtr createCell(T v){
    CellPtr c;
    c->value = v;
    return c;
}

Bool isEmptyList(LinkedList L){
    if(L->taille == 0)
        return True;
    return False;   
}

void moveKeyToStart(LinkedList L){
    setKey(L,L->first );
}

void moveKeyToNext(LinkedList L){
    Cursor pos = L->key;
    L->key = L->list[pos].next;
}


Cursor getKey(LinkedList L){
    return L->key;
}

void setKey(LinkedList L, Cursor p){
    // cursor p is a new position, 
    //if(p < L->taille)
    L->key = p;
}
Cursor getFreeCell(LinkedList L){  // first free
    Cursor pos = L->firstFree;
    L->firstFree = L->list[pos].next;
    //return L->list[pos];
    return pos;
    
}
void insertAfter(LinkedList L, T v){
    Cursor pos = L->firstFree; //getFreeCell(L);
    L->firstFree = L->list[pos].next;
    //Cursor aux = L->list[pos].next;
    L->list[pos].next = L->list[L->key].next;
    L->list[L->key].next = pos;
    //L->firstFree = aux;
    L->key = pos;

    L->taille ++;

    /// affection valeur
    L->list[pos].value = v;

}
void insertBefore(LinkedList L, T v){
    //print("\n++ %c | len(%d) ++", v, L->taille);
    Cursor pos = L->firstFree;
    //print(" # pos : %d", pos);

    if(isEmptyList(L)){
        L->list[pos].value = v;
        L->firstFree = L->list[pos].next;

        L->taille ++;
        
    }
    else{
        L->firstFree = L->list[pos].next;
        
        L->list[pos].next = L->first;
        L->first = pos;
            
        L->key = pos;
            
        L->taille ++;
            
        /// affection valeur
        L->list[L->first].value = v;
        
    }
    

              
}

Bool isFullList(LinkedList L){
    // if not free elemnet in list
    

    if(L->taille == TAILLEMAX || L->firstFree == NIL)
        return True;
    return False;
}


void deleteBefore(LinkedList L){
    // Head of list
    freeCellBefore(L, L->first);
    L->first = L->key;
    L->taille --;

}

void freeCellAfter(LinkedList L, Cursor key){
    // p is key4
    setKey(L, key);
    key = L->list[key].next;
    L->list[L->key].next = L->list[key].next;
    L->list[key].next = L->firstFree;
    L->firstFree = key;
}  
void freeCellBefore(LinkedList L, Cursor fst){
    // p is first
    setKey(L, fst);
    L->key = L->list[fst].next;
    L->list[fst].next = L->firstFree;
    L->firstFree = fst;   
} 

void deleteAfter(LinkedList L){
    //printf("\ndeleteAfter(%d) = %c |",L->key,getCurrentValue(L));

    freeCellAfter(L, L->key);
    L->taille --;
}

T getCurrentValue(LinkedList L){
    
    return L->list[L->key].value;
}

int length(LinkedList L){
    return L->taille;
}

Bool isEndOfList(LinkedList L){
    if(L->key == NIL)
        return True;
    
    return False;
}


