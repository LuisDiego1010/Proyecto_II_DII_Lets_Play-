//
// Created by isaac on 22/5/21.
//

#ifndef PROYECTO_II_GENERATION_H
#define PROYECTO_II_GENERATION_H


#include <vector>
#include "Individuo.h"
#include <tinyxml2.h>

class Generation {
public:
    Individuo* poblacion[11]{};
    Individuo* Mother;
    Individuo* Father;
    std::vector<int> representation;
    Generation();
    Generation(bool);
    Generation* children();
    Generation* mutation();
    tinyxml2::XMLElement *XML;
    void mutate();
    void declare_Parents();
    void create_representation();
};


#endif //PROYECTO_II_GENERATION_H
