//
// Created by isaac on 16/5/21.
//

#ifndef PROYECTO_II_PZ_H
#define PROYECTO_II_PZ_H


#include "Individuo.h"
#include "Generation.h"

class PZ {
public:
    static int row;
    static int col;
    static std::vector<int> Objective;
    static std::vector<int> RFit;
    static std::vector<int> GFit;
    static std::vector<int> BFit;
    static Generation* generations[15];
    void run();
    void calculate_Fitnnes(Individuo*);
};


#endif //PROYECTO_II_PZ_H
