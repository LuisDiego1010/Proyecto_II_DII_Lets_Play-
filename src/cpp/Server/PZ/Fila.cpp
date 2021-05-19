//
// Created by isaac on 16/5/21.
//

#include <cstdlib>
#include "Fila.h"
#include <cmath>
#include <ctime>

int Fila::col=0;

Fila::Fila() {
    gen= 0;
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);
    for (int i = 0; i < 4; ++i) {
        int a_rand=rand()%col;
        for (int j = 0; j < 1; j) {
            if((gen>>a_rand)%2==0){
                break;
            }
            a_rand=rand()%col;
        }
        gen=gen|(1>>a_rand);
    }
}

Fila::Fila(Fila mother,Fila father ) {
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);
    gen= 0;
    int gen_F=father.gen;
    int gen_M=mother.gen;
    int M_c= ceil(col/2);
    int F_c= floor(col/2);
    int id_counter=0;
    for (int i = 0; i < M_c; ++i) {
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
    id_counter=0;
    for (int i = 0; i < F_c; i) {
        if(id_counter>col){return;}
        if(gen_F%2==1){
            gen=gen|(1<<id_counter);
            i++;
        }
        gen_F=gen_F>>1;
        id_counter++;
    }
}
