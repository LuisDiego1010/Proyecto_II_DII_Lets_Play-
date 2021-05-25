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
int Individuo::max=0;
Individuo::Individuo() {
    Fila* tmp=(Fila*)malloc(sizeof(Fila)*row);
    chromosomas = tmp;
    for (int i = 0; i < row - 1; i) {
        auto fila = new Fila();
        aplicar_Gen(fila);
        i++;
    }
    Fila *fila = new Fila();
    fila->gen = ~Genotype;
    fila=new Fila(*fila,*fila);
    aplicar_Gen(fila);
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
        Fila* fila= nullptr;
        int probability=rand();
        if(probability%60<50){
        if(probability%2==1){
            fila=new Fila(Father->chromosomas[chromosome_c], Mother->chromosomas[chromosome_c]);

        }else{
            fila=new Fila(Mother->chromosomas[chromosome_c],Father->chromosomas[chromosome_c]);
        }
        if(validar_Gen(fila)){
            aplicar_Gen(fila);
            chromosome_c++;
            continue;
        }
        }if(probability%60<58){
            //          Mutacion
            auto mutacion=Fila();
            delete fila;
            fila= nullptr;
            if(probability%3==0){
                fila=new Fila(Mother->chromosomas[chromosome_c], mutacion);

            }else if(probability%3==1){
                fila=new Fila(mutacion, Mother->chromosomas[chromosome_c]);

            }else if(probability%3==2){
                fila=new Fila(Father->chromosomas[chromosome_c],mutacion);

            }else {
                fila=new Fila(mutacion, Father->chromosomas[chromosome_c]);

            }

            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
                continue;
            }
        }else{
//                Inversion
                delete fila;
                Fila tmpFila=Fila();
                fila= nullptr;
                tmpFila.gen=(~Genotype);
                fila=new Fila(tmpFila, tmpFila);
                if(validar_Gen(fila)){
                    aplicar_Gen(fila);
                    chromosome_c++;
                    continue;
                }

            }
        }
    Fila tmpFila=Fila();
    Fila* fila= nullptr;
    tmpFila.gen=(~Genotype);
    fila=new Fila(tmpFila, tmpFila);
    if(validar_Gen(fila)){
        aplicar_Gen(fila);
        chromosome_c++;
    }
}
