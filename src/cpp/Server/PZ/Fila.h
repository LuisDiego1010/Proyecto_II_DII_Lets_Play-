//
// Created by isaac on 16/5/21.
//

#ifndef PROYECTO_II_FILA_H
#define PROYECTO_II_FILA_H


class Fila {
public:
    Fila();

    Fila(Fila mother, Fila father);

    static int col;
    int gen=0;
};


#endif //PROYECTO_II_FILA_H
