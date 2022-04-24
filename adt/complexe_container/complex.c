#include "complex.h"


Complex addition(Complex C1, Complex C2){
    Complex S;
    S.reel = C1.reel + C2.reel;
    S.img = C1.img + C2.img;

    return S;
}

// (a + i.b) x (a' + i.b') = (aa' – bb') + i (ab' + ba')
//(a + i.b) x (a – i.b) = a² + b²

Complex multiplication(Complex C1, Complex C2){
    Complex P;
    P.reel = (C1.reel*C2.reel - C1.img*C2.img);
    P.img = (C1.reel*C2.img + C2.reel*C1.img);
    return P;
} 

double module(Complex C){
    return sqrt(C.reel*C.reel + C.img*C.img);
}

Complex* createComplexe(double r, double i){
    Complex *C = (Complex *) malloc(sizeof(Complex));
    if(C == NULL) exit(EXIT_FAILURE);
    (*C).reel = r;
    C->img = i;
    return C;
}

void afficheComplex(Complex Z){
    printf("%f + %fi",Z.reel,Z.img);
}
