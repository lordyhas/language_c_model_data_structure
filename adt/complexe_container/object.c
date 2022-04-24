#include "object.h"

void createContainerStatic(Object tab[], int n){
    for (int i = 0; i < n; i++)
    {
        tab[i].isNotEmpty = False;
    }    
}


Object* createContainer(int n){
    Object* o = malloc(n*sizeof(Object));
    return o;
}


Object* initContainer(Object *container, int n){
    for (int i = 0; i < n; i++)
        (container+i)->isNotEmpty = False;   

    return container;
}

void addContainer(Object tab[], int n, Complex c){

    for (int i = 0; i < n; i++){
            if(!((tab+i)->isNotEmpty)){
                (tab+i)->complexe.reel = c.reel;
                (tab+i)->complexe.img = c.img;
                (tab+i)->isNotEmpty = True;
            } 
    }   
}

void insertContainer(Object tab[], int n, Complex c, int i){
    if(i < n)
        (tab+i)->complexe.reel = c.reel;
        (tab+i)->complexe.img = c.img;
        

}
void printContainer(Object tab[], int n){
    for (int i = 0; i < n; i++)
    {
        if((tab[i].isNotEmpty) == True){
            Complex c = (tab+i)->complexe;
            print("%.2lf+%.2lfi\n",c.reel,c.img);
        }
        //print("-  * * * -\n");
    }
    
}
void deleteContainer(Object tab[], int n, Complex c){
    for (int i = 0; i < n; i++){
        if(((tab+i)->isNotEmpty) == True){
            if ((tab+i)->complexe.reel == c.reel && 
            (tab+i)->complexe.img == c.img){
                (tab+i)->isNotEmpty = False;
            }  
        }
    }
    
}

void destroyContainer(Object tab[], int n){  
    for (int i = 0; i < n; i++){
        (tab+i)->isNotEmpty = False;
    }
}

Complex valueContainer(Object tab[], int n){
    Complex c;
    for (int i = 0; i < n; i++){
        if(((tab+i)->isNotEmpty)){
            c = (tab+i)->complexe;
        } 
    }
    return c;
}






// int main(int argc, char const *argv[])
// {
//     puts("\n============= Start programme ============\n");
//     int n = 10;
//     Object tab[3] = {
//         {{7,2},False},
//         {{14,4},False},
//         {{18,5},False}
//     };
//     tab[0].complexe.img;
//     tab[0].isNotEmpty;




    
//     puts("\n\n============== Exit programme ============\n");
    
//     return 0;

// }