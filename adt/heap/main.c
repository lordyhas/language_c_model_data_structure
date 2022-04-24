// TSHELEKA KAJILA HASSAN

#include "util.h"
#include "heap.h"
//#include "object.h"

void displayHeap(Heap h){
    for (Cursor i = 1; i < sizeOfHeap(h); i++){
        print("%c, ",getValue(h,i));
    }
}

int main(int argc, char const *argv[]){
    Heap h = createHeap();
    char c = 67; 
    //addHeap(h,'F');
    addHeap(h,'J');
    addHeap(h,'B');
    addHeap(h,'H');
    //displayHeap(h);
    puts("");
    for (size_t i = 0; i < 5; i++){
        addHeap(h,c);
        c++;   
    }
    print("\n--------- Entasse ------------ \n");
    displayHeap(h);
    print("\n--------- Detasse ------------ \n");
    deleteRoot(h);
    displayHeap(h);
    print("\n--------- Detasse ------------ \n");
    deleteRoot(h);
    
    displayHeap(h);
    

   

    //deleteRoot(h);

    //displayHeap(h);
    

    

    


}
/*    DLL L = createDLList();
    if(L==NULL) return -1;
    char a = 65;
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(L,a);
        a++;
    }
    printList(L);
    moveKeyToStart(L);
    //moveKeyToNext(L);
    //moveKeyToNext(L);
    insertAfterKey(L, '0');

    printList(L);
    deleteAtStart(L);
    printList(L);

    
    //permutationSymetrique(L);
    //puts(" Apres permutation  :");
    //printList(L);

    puts("--------------------------");
    
    // L = createDLList();
    // insertAtEnd(L,'k');
    // insertAtEnd(L,'a');
    // insertAtEnd(L,'y');
    // insertAtEnd(L,'a');
    // insertAtEnd(L,'k');
    // printList(L);

    // if(palindrome(L)) print("C'est palindrome");
    // else print("C'est ne pas palindrome");
    
    
    return 0;
}*/