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
    unsigned int Genotype=0;
    int fitnnes=0;
    /**
     * \brief Generate a New Random Individuo
     */
    Individuo();
    /**
     * \brief Generate a New Individuo by mixin the gen of each Fila of two Individuos
     * @param Father
     * @param Mother
     */
    Individuo(Individuo* Father, Individuo* Mother);
    /**
     * \deprecated
     * Detect if the Gen of a Fila is valid to aplicate in this Individuo.
     * @return
     */
    bool validar_Gen(Fila*);
    /**
     * Inserter the Fila in the Chromosoma and the Fila Gen in the Genotype.
     */
    void aplicar_Gen(Fila*);
};


#endif //PROYECTO_II_INDIVIDUO_H
