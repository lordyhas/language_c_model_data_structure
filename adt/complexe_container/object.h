//#include "util.h"
#include "complex.h"

typedef struct object {Complex complexe; Bool isNotEmpty;} Object;


void createContainerStatic(Object tab[], int n);
void addContainer(Object tab[], int n, Complex c);
void insertContainer(Object tab[], int n, Complex c, int i);
void printContainer(Object tab[], int n);
void deleteContainer(Object tab[], int n, Complex c);
void destroyContainer(Object tab[], int n);
Complex valueContainer(Object tab[], int n);

Object* createContainer(int n);
Object* initContainer(Object *container,int n);


