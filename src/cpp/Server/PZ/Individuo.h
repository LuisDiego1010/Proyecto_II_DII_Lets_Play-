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
    Fila** chromosomas;
    int Genotype ;
    int fitnnes;
    Individuo();
    bool validar_Gen(Fila*);
    void aplicar_Gen(Fila*);
    void calculate_Fitnnes();
};


#endif //PROYECTO_II_INDIVIDUO_H
