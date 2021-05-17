//
// Created by isaac on 16/5/21.
//

#include "Individuo.h"
int Individuo::row=0;
int Individuo::col=0;

Individuo::Individuo() {
    chromosomas= new Fila*[row];
    Genotype=0;

}

bool Individuo::validar_Gen(Fila* gen) {
int gen_c=0;
    for (int i = 0; (i < row*col)&&(gen_c<col); ++i) {
        if(((gen->gen>>i)%2)!=0){
            if(((Genotype>>i)%2)!=0){
                return false;
            }
        }
    }
    return true;
}

void Individuo::aplicar_Gen(Fila* gen) {
    int gen_c=0;
    for (int i = 0; (i < row*col)&&(gen_c<col); ++i) {
        if(((gen->gen>>i)%2)!=0){
            Genotype=Genotype|(1<<i);
        }
    }
    for (int i = 0; i < row; ++i) {
        if(chromosomas[i]== nullptr){
            chromosomas[i]=gen;
            return;
        }
    }
}
