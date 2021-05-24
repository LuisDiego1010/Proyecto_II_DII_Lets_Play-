//
// Created by isaac on 22/5/21.
//

#ifndef PROYECTO_II_GENERATION_H
#define PROYECTO_II_GENERATION_H


#include <vector>
#include "Individuo.h"

class Generation {
public:
    Individuo* poblacion[8]{};
    Individuo* Mother;
    Individuo* Father;
    std::vector<int> representation;
    Generation();
    Generation(bool);
    Generation* children();
    void declare_Parents();
    void create_representation();
};


#endif //PROYECTO_II_GENERATION_H
