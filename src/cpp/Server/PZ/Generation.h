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
    /**
     * Generate a random Generation
     */
    Generation();
    /**
     * Generate a Empty Generation
     */
    Generation(bool);
    /**
     * Generate a new Generation by mixing Individuos of this Generation
     * @return the new generation
     */
    Generation* children();
    /**
     * Algortih to augment the genetic diversity to avoid generations constants repetiton
     * two possibilities:
     * take the better Individuo and mix wit another a individuo of the generation
     * OR, Create a New random Individuo and mix with a another random Individuo of the generation.
     * @return the new generation.
     */
    Generation* mutation();

    tinyxml2::XMLElement *XML;

    /**
     * Auxiliary of mutation
     * Swap the position of to Filas of the Better Individuo
     */
    void mutate();
    /**
     * Calculate the best Individuo and the second Best Individuo of the generation using the fitnnes asosiated
     */
    void declare_Parents();
    /**
     * Calculate the representation of the Image order of the best Individuo.
     */
    void create_representation();
};


#endif //PROYECTO_II_GENERATION_H
