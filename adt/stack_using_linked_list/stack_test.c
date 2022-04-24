#include "util.h"
#include "stack.h"
//#include "object.h"

void printStack(Stack L){

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


int main(int argc, char const *argv[]){
    //print("========== ### ============");
    puts("");

    Stack stack = (Stack) malloc(sizeof(LinkedList_));
    createStack(stack);
    char a = 67;
    //stack->list[0].value = 48;
    if(stack == NULL) return -1;
    push(stack, a++);
    push(stack, a++);
    push(stack, a++);
    push(stack, a++);
    push(stack, a++);

    
    puts(" --- Apres empile (4 fois) --- ");
    printStack(stack);

    pop(stack);
    pop(stack);

    puts(" --- Apres empile (2 fois) --- ");

    printStack(stack);
    
    //moveKeyToNext(stack); 
    return 0;
}
