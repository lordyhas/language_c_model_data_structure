// Fait par TSHELEKA KAJILA HASSAN
#include "util.h"
//#include "list.h"
#include "object.h"


int main(int argc, char const *argv[])
{
    Object tab[N];
    Complex *c = createComplexe(2,3);
    Complex *a = createComplexe(7,3);
    //c.reel = 2;
    //c.img = 3;
    createContainerStatic(tab,N);
    addContainer(tab, N, *c);
    printContainer(tab,N);
    Complex p = multiplication(*c,*a);
    Complex s = addition(*c,*a);
    //p.reel = 5;
    //p.img = 7;
    print("########### 1 #########\n");
    insertContainer(tab, N, p, 2);
    insertContainer(tab, N, s, 4);
    printContainer(tab,N);
    print("########### 2 #########\n");
    deleteContainer(tab, N, *c);
    printContainer(tab,N);
    print("########### 3 #########\n");
    destroyContainer(tab,N);
    printContainer(tab,N);
    print("Le conteniare est detruit");


    puts("\n\n  Fait par TSHELEKA KAJILA HASSAN ");






    
    
    

    
    return 0;
}