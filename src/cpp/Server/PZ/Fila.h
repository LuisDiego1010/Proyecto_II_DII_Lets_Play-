/**
  * @file Fila.h
  * */


#ifndef PROYECTO_II_FILA_H
#define PROYECTO_II_FILA_H


class Fila {
public:
    /**
     * \brief Create a New Fila With randmo gen, the contain col quantity of ones
     */
    Fila();
    /**
     * \brief create a New Fila with the gen of maf mother and father.
     * take half of each.
     * 1/60 % fo inversion.
     * 9/60 % of mutation.
     * @param mother
     * @param father
     */
    Fila(Fila mother, Fila father);

    static int col;
    static int row;
    unsigned int gen=0;
};


#endif //PROYECTO_II_FILA_H
