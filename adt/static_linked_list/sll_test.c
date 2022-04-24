

// author : @lordyhas - Lordy Hassan K. 
// structure : Simply Static Linked List

#include "util.h"
#include "static_linked_list.h"


void printList(LinkedList L);
void supprimerOccurence(LinkedList L);
Bool estOrdonner(LinkedList L);
void supprimerOccurence(LinkedList L);
void compteMinimaMaxima(LinkedList L, LinkedList max, LinkedList min);
void remplireList(LinkedList L);


int main(int argc, char const *argv[]){ 
    
    // allocation d'espace pour le container 
    LinkedList L = (LinkedList) malloc (sizeof(LinkedList_));

    // initialisation de deux listes pour les minima et les maxima 
    LinkedList listMax = (LinkedList) malloc (sizeof(LinkedList_)); 
    LinkedList listMin = (LinkedList) malloc (sizeof(LinkedList_));
    if (L == NULL)
    {
        printf("\nErreur d'allocation : Le container est toujours NULL");
        return 1;
    }

    

    // creation de la liste
    createList(L);

    // remplireList(L): n'est pas une primitive 
    // elle permet de remplir la liste avec 7 char, au hasard
    remplireList(L);

    print("\nLa liste Global :");
    printList(L); // afficher la liste
      
    print("\n--------- Minima Maxima ----------\n");      
     
    compteMinimaMaxima(L,listMax, listMin);
    print("\nLa liste de Maxima :");
    printList(listMax);
    print("\nLa liste de Minima :");
    printList(listMin);

    print("\n----------- Supprime Occurence --------\n");
    print("\nAvant suppression des occurences :");
    printList(L);
    supprimerOccurence(L);
    print("\nApres suppression des occurences :"); 
    printList(L);
    
    
    return 0;
}



void printList(LinkedList L){
   
    if (isEmptyList(L)) return ;
    char a;
    moveKeyToStart(L);
    printf("\n|");
    while (!isEndOfList(L)){
        a = getCurrentValue(L);
        printf(" %c |", a);
        moveKeyToNext(L);       
    }
    printf("\n");

}

Bool estOrdonner(LinkedList L){
    if (isEmptyList(L)) return False ;
    moveKeyToStart(L);
    while (!isEndOfList(L)){
        char a = getCurrentValue(L);
        moveKeyToNext(L);
        char b = getCurrentValue(L);
        if(a < b) return False;
    }
    return True;     
}


void supprimerOccurence(LinkedList L){
    if (isEmptyList(L)) return ;
    Cursor i, j ;
   // LinkedList tab = L;
    moveKeyToStart(L);

    while (!isEndOfList(L)){
        i = getKey(L);
        char a =  getCurrentValue(L);
        moveKeyToStart(L);
        while(!isEndOfList(L)){
            j = getKey(L);
            moveKeyToNext(L);
            char b =  getCurrentValue(L);
            //printf("%c == %c \n",a,b);
            
            if(a==b){
               // printf("%d == %d : ok\n",a,b);
                setKey(L, j);
                deleteAfter(L);
                //printf("%d == %d : ok\n",a,b);

            }

        }
        setKey(L, i);
        moveKeyToNext(L);
    }
}

void compteMinimaMaxima(LinkedList L, LinkedList max, LinkedList min){
    if (isEmptyList(L)) return ;
    createList(max);
    createList(min);
    if (max == NULL || min == NULL){
        printf("\nErreur d'allocation : pour ListeMin et ListeMax");
        exit(EXIT_FAILURE);
    }
    int i = 0, j = 0, countMax = 0, countMin = 0;
    moveKeyToStart(L);
    while (!isEndOfList(L)){
        char a = getCurrentValue(L);
        moveKeyToNext(L);
        char b = getCurrentValue(L);

        if(a < b){
            countMax ++;
        }
        else{
            if(countMax >= 1){
                if(length(max) == 0) insertBefore(max, a);
                else insertAfter(max, a);
                //max[i] = a;
                i++;
                countMax = 0;
            }
        }


        if (a > b){
            countMin ++;
        }
        else {
            if (countMin >= 1){
                if(length(min) == 0) insertBefore(min, a);
                else insertAfter(min, a);
                j++;
                countMin = 0;
            }           
        } 
                           
    }
    // comme on peut pas retourner deux valeur;
    // i et j qui sont le nombre de maxima et minima
    printf("nbre de maxima = %d, \nnbre de minima = %d",i,j); 
}

void remplireList(LinkedList L){
    char v = 66;

    insertBefore(L,v);
    v--;

    for (int i = 0; i < 4; i++){
        insertAfter(L, v);
        v++;
        v++;
    }
    insertAfter(L, 'A');
    insertAfter(L, 'K');


}
