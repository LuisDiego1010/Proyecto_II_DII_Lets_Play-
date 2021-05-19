//
// Created by isaac on 16/5/21.
//

#include "Individuo.h"
int Individuo::row=0;
int Individuo::col=0;

Individuo::Individuo() {
    chromosomas= new Fila[row];
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
        if(chromosomas[i].gen== 0){
            chromosomas[i]=*gen;
            return;
        }
    }
}

Individuo::Individuo(Individuo* Father, Individuo* Mother) {
    int chromosome_c=0;
    while (chromosome_c<row-1){
        Fila* fila=new Fila(Father->chromosomas[chromosome_c], Mother->chromosomas[chromosome_c]);
        if(validar_Gen(fila)){
            aplicar_Gen(fila);
            chromosome_c++;
        }else{
            *fila= Fila(Mother->chromosomas[chromosome_c],Father->chromosomas[chromosome_c]);
            if(validar_Gen(fila)){
                aplicar_Gen(fila);
                chromosome_c++;
            }else{
//                Mutacion
                *fila= Fila();
                if(validar_Gen(fila)){
                    aplicar_Gen(fila);
                    chromosome_c++;
                }else{
                    delete fila;
                }
            }
        }
    }
}
