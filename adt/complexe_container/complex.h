#include "util.h"

typedef struct complexe {double reel; double img;} Complex;

Complex* createComplexe(double r, double i);
Complex addition(Complex C1, Complex C2);
Complex multiplication(Complex C1, Complex C2); 
double module(Complex C);
void afficheComplex(Complex Z);
void createComplexDynamic(Complex* c);