//
// Created by isaac on 16/5/21.
//

#ifndef PROYECTO_II_INDIVIDUO_H
#define PROYECTO_II_INDIVIDUO_H


#include "Fila.h"

class Individuo {
public:
    static int row;
    static int col;
    static int max;
    Fila* chromosomas;
    int Genotype=0;
    int fitnnes=0;
    Individuo();
    Individuo(Individuo* Father, Individuo* Mother);
    bool validar_Gen(Fila*);
    void aplicar_Gen(Fila*);
};


#endif //PROYECTO_II_INDIVIDUO_H
