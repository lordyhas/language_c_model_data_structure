#include "doubly_linked_list.h"
/// -------------- 
DCell createCell(T p){
    DCell cell = (DCell) malloc(sizeof(DCell_));
    if(cell == NULL) return NULL;
    cell->value = p;
    cell->next = NULL;
    cell->prev = NULL;
}

DLL createDLList(void){
    DLL L = (DLL) malloc(sizeof(DLinkedList_));
    if(L){
        L->size = 0;
        L->first = NULL;
        L->key = NULL;
        L->last = NULL;
    }
    return L;

}

int length(DLL L){
    return L->size;
}

T getCurrentValue(DLL L){
    return L->key->value;
}
Cursor getKey(DLL L){
    return L->key; 
}
void setKey(DLL L, Cursor newKey){
    L->key = newKey;
}

void moveKeyToStart(DLL L){
    L->key = L->first;

}

void moveKeyToEnd(DLL L){
    L->key = L->last;
}

void moveKeyToNext(DLL L){
    L->key = L->key->next;
}

void moveKeyToPrev(DLL L){
    L->key = L->key->prev;
}

Bool isListEmpty(DLL L){
    if(L->size==0) return True;
    return False;
}
Bool isEndOfList(DLL L){
    if (L->key == NULL) return True;
    return False;
}
Cursor getFirst(DLL L){
    return L->first;
}
Cursor getLast(DLL L){
    return L->last;
}

void insertAtEnd(DLL L, T v){
    DCell cell = createCell(v);

    if(isListEmpty(L)){
        cell->next = NULL;
        cell->prev = NULL;
        L->first = cell;
        L->last = cell;
        L->key = cell;
        
    }
    else{
        L->last->next = cell;
        cell->prev = L->last;
        cell->next = NULL;
        L->last = cell;
    }
    L->size ++;
}
void insertAfterKey(DLL L, T v){
    
    Cursor cell = createCell(v);
    if(isListEmpty(L)){
        cell->next = NULL;
        cell->prev = NULL;
        L->first = cell;
        L->last = cell;  
        L->key = cell;  
    }
    else{
        //Cursor nextC = L->key->next;
        cell->next = L->key->next;
        L->key->next->prev = cell;
        L->key->next = cell;
        
        cell->prev = L->key;       
        //print("\n cell : %c ",cell->value);
        //print("\n key -- : %c ",L->key->value);
    }
    L->size ++;       
}
void insertAtStart(DLL L, T v){
    DCell cell = createCell(v);
    if(isListEmpty(L)){
        cell->next = NULL;
        cell->prev = NULL;
        L->first = cell;
        L->last = cell; 
        L->key = cell;  
    }

    else{
        L->first->prev = cell;
        cell->next = L->first;
        cell->prev = NULL;
        L->first = cell;
    }
    
    L->size ++;
}


/// --- OK --
void deleteAtEnd(DLL L){
    if(isListEmpty(L)) return;
    if(L->last == L->first){
        free(L);
        L = NULL;
        L = createDLList();
    }
    else{
        Cursor c = L->last;
        L->last = L->last->prev;
        L->last->next = NULL;

        c->next = NULL;
        c->prev = NULL;

        free(c);
    }

    L->size --;
}

void deleteAfterKey(DLL L){
    if(isListEmpty(L)) return;

    Cursor c = L->key->next;
    if(c==NULL) return;
    L->key->next = L->key->next->next;

    c->next = NULL;
    c->prev = NULL;

    free(c);
    L->size --;

}



void deleteAtStart(DLL L){
    if(isListEmpty(L)) return;

    if(L->last == L->first){
        free(L);
        L = NULL;
        L = createDLList();
    }
    else{
        Cursor c = L->first;
        L->first = L->first->next;
        L->first->prev = NULL;
        

        c->next = NULL;
        free(c); 
    }


    L->size--;
}


