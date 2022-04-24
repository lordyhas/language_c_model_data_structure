#include "util.h"
//#include "file.h"
#include "stack.h"

/*****************************
 * TSHELEKA KAJILA HASSAN    *
 * L2 - SC. INFO / CS        *
 * STRUCTURE DES DONNNÉES    *
 *                           *
******************************/
void parcoursInfixePile(Node root){
    Stack stack = (Stack) malloc(sizeof(LinkedList_));
    createStack(stack);
    if(stack == NULL || root == NULL) return;

    while(1){

    }

    
}

void parcoursProfondeurPile(Node root){
    Stack stack = (Stack) malloc(sizeof(LinkedList_));
    createStack(stack);
    if(stack == NULL || root == NULL) return;
    
    Node node = createNode(0);
    memcpy(node,root, sizeof(*node));
    //node = root;
    
    if(node != NULL){
        if(getNodeRight(node) != NULL)
            push(stack, getNodeRight(node));
        
        node = getNodeLeft(node);
    }
    else return;
    
    while(!isStackEmpty(stack)){
        if(node != NULL){
            if(getNodeRight(node) != NULL)
                push(stack, getNodeRight(node));
            /// Traitement ici
            printf("%d\n", getValueNode(node));

            node = getNodeLeft(node);
        }
        else{
            node = valueOfStack(stack);
            pop(stack);
        }
    }
}

void parcoursProfondeur(Node root, int space){
    //affichage en profondeur
    const int COUNT = 5;

    if (root == NULL) return;
    if(getValueNode(root) == -1) return;
  
    space += COUNT;
    parcoursProfondeur(getNodeRight(root), space);
    
    puts("");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", getValueNode(root));
  
    parcoursProfondeur(getNodeLeft(root), space);
}
/*
void parcoursHierarechique(Node node, Queue F){
    Node e = createNode(0);
    int i = 1, j = 2;
    enqueue(F,node);
    
    while(!isQueueEmpty(F)){
        e = valueOfQueue(F);
        
        if(i%j==0){
            j*=2;
            print("\n");
            //print("");
        } 
        print("* %d *", getValueNode(e));
     
        if(getNodeLeft(e) != NULL){
            enqueue(F,getNodeLeft(e));
        }
        if(getNodeRight(e) != NULL){ 
            enqueue(F,getNodeRight(e));
        }

        dequeue(F);
        i++;
        

    }


}
*/
void printTree(Node root){
    parcoursProfondeur(root,0);
}



int main(int argc, char const *argv[]){
    puts(" *** start *** ");

    char tab[5];
    for(int i =0; i< 5; i++)
        tab[i]= 'H';
    for(int i =0; i< 5; i++)
        print("tab[%d] = %c,\n",i,tab[i]);
    
    puts(" *** end *** ");
    
    
    
    
    
    
    
    /*puts(" *** Arbre binaire des recherches *** ");
    Queue F = createQueue();
    if(F == NULL) return -1;
    Node node = createNode(5);
    
   
    addNode(node, createNode(2));
    addNode(node, createNode(3));
    addNode(node, createNode(6));
    addNode(node, createNode(7));
    addNode(node, createNode(1));

    

    printTree(node);
    
    removeNode(node,createNode(2));
    
    print(" === Apres suppression de %d dans l'arbre === ", 2);

    //parcoursHierarechique(node, F);
    //print(" root = %d \n", getValueNode(node));
    printTree(node);*/

    


}
