#include "util.h"
#include "queue.h"
//#include "object.h"




void printList(DLL F){
    if(isListEmpty(F)) return;
    if(F==NULL) return;
    moveKeyToStart(F);
    while (!isEndOfList(F)){
        print("%c, | ", getCurrentValue(F));
        moveKeyToNext(F);
    }

    print("\n");
    

}



int main(int argc, char const *argv[]){
    puts("--------------------------");

    Queue F = createQueue();


    if(F == NULL) return -1;

    char a = 65;
    for (int i = 0; i < 5; i++)
    {
        enqueue(F,a);
        //print("%c",a);
        a++;
    }
    puts("\n------------- Empile-------------");

    printList(F);
    puts("------------ Depile --------------");
    dequeue(F);
    printList(F);
    puts("------------ Depile --------------");
    dequeue(F);
    printList(F);

    puts("--------------------------");

    
    
    return 0;
}

