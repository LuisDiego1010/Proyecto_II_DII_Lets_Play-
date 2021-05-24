//
// Created by isaac on 16/5/21.
//

#include <cstdlib>
#include "Fila.h"
#include <cmath>
#include <ctime>

int Fila::col=0;
int Fila::row=0;

Fila::Fila() {
    gen= 0;
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);
    for (int i = 0; i < col; ++i) {
        int a_rand=rand()%(col*row);
        for (int j = 0; j < 1; j) {
            if((gen>>a_rand)%2==0){
                break;
            }
            a_rand=rand()%(col*row);
        }
        int bit=1;
        bit=bit<<a_rand;
        gen=gen|bit;
    }
}

Fila::Fila(Fila mother,Fila father ) {
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);
    gen= 0;
    unsigned int gen_F=father.gen;
    unsigned int gen_M=mother.gen;
    float coltmp=col;
    int M_c= ceil(coltmp/2);
    int F_c= floor(coltmp/2);
    int id_counter=0;
    for (int i = 0; i < M_c; i) {
        if(gen_F%2==1){
            i++;
        }
        gen_F=gen_F>>1;
        id_counter++;
    }
    id_counter=0;

    for (int i = 0; i < M_c; i) {
            if(gen_M%2==1){
                gen=gen|(1<<id_counter);
                i++;
            }
            gen_M=gen_M>>1;
            id_counter++;
    }
    for (int i = 0; i < F_c; i) {
        if(gen_F%2==1){
            gen=gen|(1<<id_counter);
            i++;
        }
        gen_F=gen_F>>1;
        id_counter++;
        if(id_counter>col*row){return;}

    }
}
