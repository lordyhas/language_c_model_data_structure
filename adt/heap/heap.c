#include "heap.h"


void echange(T *x, T *y){
    T aux;
    aux = *x; *x=*y; *y = aux;
}

Heap createHeap(){
    Heap h = (Heap) malloc(sizeof(struct heap));
    h->tab = (T*) malloc (sizeof(T)*4);
    h->sizeMax = 4;
    h->length = NIL;
    
}

Bool isHeapEmpty(Heap h){
    if (h->length==NIL)
        return True;
    return False; 
}


void reorganizationASC(Heap h){
    int i,j;
    /*if(h->length-1){
        h->tab[i] < h->tab[j]

    }*/
    j = h->length-1;

    i = (int) j/2;

    while(h->tab[i] > h->tab[j]){
        echange(&(h->tab[i]), &(h->tab[j]));       
        j = i;
        i = j/2;
    }

    
}
void reorganizationDESC(Heap h){
    int i,j,k;
    T a,b;
    i = 1;

    //a = h->tab[i];
    //b = h->tab[j]; 

    while (True){
        j = 2*i;
        k = 2*i+1;
        if(k > h->length) break;
       
        if(h->tab[k] > h->tab[j]){
            if(h->tab[i] > h->tab[j] ){
                echange(&(h->tab[i]), &(h->tab[j]));
                i = j;
            }
            else break;
                
        }
        else{
            if(h->tab[i] > h->tab[k]){
                echange(&(h->tab[i]), &(h->tab[k]));
                i = k;
            }
            else break;
                
        }

        
    }
}


void addHeap(Heap h,T v){

    if(h->length == h->sizeMax){
        h->tab = (T*) realloc(h->tab, sizeof(T)*2);
        h->sizeMax*=2;
    }

    if (isHeapEmpty(h))
    {
        h->tab[1] =  v;
        h->length = 2;
    }

    else{
        h->tab[h->length] =  v;
        h->length ++;
        reorganizationASC(h);
    }

    

}

void deleteRoot(Heap h){
    T* last = &(h->tab[h->length-1]);
    h->tab[1] = *last;
    //last = NULL;
    
    h->length--;
    reorganizationDESC(h);
    
}

void destroyHeap(Heap h){
    free(h->tab);
    free(h);
    h = NULL;
}

T valueOfHeap(Heap h){
    return h->tab[1];
}
int sizeOfHeap(Heap h){
    return h->length;
}
T getValue(Heap h, Cursor i){
    if(i> 0 && i < h->length)
        return h->tab[i];
    return NIL;
}

void setValue(Heap h, T v, Cursor i){
    h->tab[i] = v;
}

Cursor childRight(Cursor father){
    return 2*father;
        
}
Cursor childLeft(Cursor father){
    return 2*father+1;
}

Cursor father(Cursor child){
    return child/2;
}


