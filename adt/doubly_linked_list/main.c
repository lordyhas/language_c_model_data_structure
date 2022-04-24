#include "util.h"
#include "doubly_linked_list.h"
//#include "object.h"




void printList(DLL L){
    if(isListEmpty(L)) return;
    moveKeyToStart(L);
    while (!isEndOfList(L)){
        print("%c, | ", getCurrentValue(L));
        moveKeyToNext(L);
    }

    print("\n");
    

}


T renvoiValeurDuCurseur(DLL L, Cursor c){
    setKey(L, c);
    return getCurrentValue(L);
}

void permutationSymetrique(DLL L){
    if(isListEmpty(L)) return;
    //moveKeyToEnd(L);
    //moveKeyToPrev(L);
    DCell_ i, j;
    i = *(getFirst(L));
    j = *(getLast(L));
    
    deleteAtStart(L);
    
    insertAtStart(L, renvoiValeurDuCurseur(L,&j));
    deleteAtEnd(L);
    insertAtEnd(L, renvoiValeurDuCurseur(L,&i));

    printList(L);
    
    for (int k = 1; k < length(L)/2; k++)
    {
        
        setKey(L, &i);
        moveKeyToNext(L);
        i = *getKey(L);
        
        setKey(L, &j);
        moveKeyToPrev(L);
        j = *getKey(L);

        setKey(L, &i);
        moveKeyToPrev(L);
        deleteAfterKey(L);
        
        
        insertAfterKey(L, renvoiValeurDuCurseur(L,&j));
        printList(L);

        setKey(L, &j);
        moveKeyToPrev(L);
        deleteAfterKey(L);
        insertAfterKey(L, renvoiValeurDuCurseur(L,&i));

    

    }
    
}


// void permutationCirculaire(DLL L){
//     if(isListEmpty(L)) return;
//     Cursor c = getLast(L);
//     deleteAtEnd(L);
//     insertAtStart(L, renvoiValeurDuCurseur(L,c));   
// }


void permutationCirculaire(DLL L){
    Cursor k ;
    for (int i = 0; i < length(L)-1; i++){
        k = getLast(L);
        insertAtStart(L, renvoiValeurDuCurseur(L,k));
        deleteAtEnd(L);
        
    }    
}


Bool palindrome(DLL L){
    if(isListEmpty(L)) return False;
    Cursor i, j;
    char a,b;
    i = getFirst(L);
    j = getLast(L);
    

    int count = length(L)/2;

    for (int k = 0; k < count; k++){
        a = renvoiValeurDuCurseur(L,i);
        b = renvoiValeurDuCurseur(L,j);

        if (a!=b) return False;
        
        setKey(L,i);
        moveKeyToNext(L);
        i = getKey(L);

        setKey(L,j);
        moveKeyToPrev(L);
        j = getKey(L);
    }
    
    return True;
}



int main(int argc, char const *argv[]){
    DLL L = createDLList();
    if(L==NULL) return -1;
    char a = 65;
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(L,a);
        a++;
    }
    printList(L);
    
    permutationCirculaire(L);
    puts(" Apres permutation circulaire :");
    printList(L);

    puts("--------------------------");
    
    L = createDLList();
    insertAtEnd(L,'k');
    insertAtEnd(L,'a');
    insertAtEnd(L,'y');
    insertAtEnd(L,'a');
    insertAtEnd(L,'k');
    printList(L);

    if(palindrome(L)) print("C'est palindrome");
    else print("C'est ne pas palindrome");
    
    
    return 0;
}