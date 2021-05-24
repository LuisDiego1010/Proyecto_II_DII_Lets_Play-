//
// Created by isaac on 16/5/21.
//

#include <malloc.h>
#include <cmath>
#include <iostream>
#include <bitset>
#include "Individuo.h"
int Individuo::row=0;
int Individuo::col=0;
Individuo::Individuo() {
    Fila* tmp=(Fila*)malloc(sizeof(Fila)*row);
    chromosomas = tmp;
    for (int i = 0; i < row - 1; i) {
        auto fila = new Fila();
        if (validar_Gen(fila)) {
            aplicar_Gen(fila);
            i++;
        } else {
            delete fila;
        }

    }
    Fila *fila = new Fila();
    fila->gen = ~Genotype;
    fila=new Fila(*fila,*fila);
    if (validar_Gen(fila)) {
        aplicar_Gen(fila);
    }
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
        if(chromosomas[i].gen== 0){
            chromosomas[i]=*gen;
            return;
        }
    }
}

Individuo::Individuo(Individuo* Father, Individuo* Mother) {
    int chromosome_c=0;
    Fila* tmp=(Fila*)malloc(sizeof(Fila)*row);
    chromosomas = tmp;
    while (chromosome_c<row-1){
        //Herencia
        Fila* fila=new Fila(Father->chromosomas[chromosome_c], Mother->chromosomas[chromosome_c]);
        if(validar_Gen(fila)){
            aplicar_Gen(fila);
            chromosome_c++;
            continue;
        }
        *fila= Fila(Mother->chromosomas[chromosome_c],Father->chromosomas[chromosome_c]);
        if(validar_Gen(fila)){
            aplicar_Gen(fila);
            chromosome_c++;
            continue;

        }else{
//          Mutacion
            auto mutacion=Fila();
            *fila= Fila(Mother->chromosomas[chromosome_c], mutacion);
            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
                continue;
            }
            *fila=Fila(mutacion, Mother->chromosomas[chromosome_c]);
            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
                continue;
            }
            *fila=Fila(Father->chromosomas[chromosome_c],mutacion);
            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
                continue;
            }
            *fila=Fila(mutacion, Father->chromosomas[chromosome_c]);
            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
                continue;
            }else{
//                Inversion
                fila->gen=~Genotype;
                if(validar_Gen(fila)){
                    aplicar_Gen(fila);
                    chromosome_c++;
                    continue;
                }

            }
        }
    }
    Fila* fila=new Fila();
    fila->gen=~Genotype;
    if(validar_Gen(fila)){
        aplicar_Gen(fila);
        chromosome_c++;
    }

}

