//
// Created by isaac on 22/5/21.
//

#include <iostream>
#include "Generation.h"
Generation::Generation(bool empty){
    Mother= nullptr;
    Father= nullptr;
    representation=std::vector<int>(Individuo::col*Individuo::col, 0);

}
Generation::Generation() {
    Mother= nullptr;
    Father= nullptr;
    representation=std::vector<int>(Individuo::col*Individuo::col, 0);
    for (int i = 0; i < 8; ++i) {
        auto tmp=new Individuo();
        poblacion[i]= &*tmp;
    }
}

Generation* Generation::children() {
    auto tmpGeneration= new Generation(true);
    tmpGeneration->Mother= nullptr;
    tmpGeneration->Father= nullptr;
    tmpGeneration->representation=std::vector<int>(Individuo::col*Individuo::col, 0);

    for (int i = 0; i < 8; ++i) {
        auto tmp=new Individuo(Mother,Father);
        tmpGeneration->poblacion[i]= &*tmp;
    }
    return tmpGeneration;
}

void Generation::declare_Parents() {
    Mother=poblacion[0];
    Father=poblacion[1];
    for (int i = 1; i < 8; ++i) {
        if(poblacion[i]->fitnnes<Mother->fitnnes){
            Father=Mother;
            Mother=poblacion[i];
        }
    }
}

void Generation::create_representation() {
    for (int i = 0; i < Individuo::row; ++i) {
        int id=0;
        int conter=0;
        unsigned int gen=Mother->chromosomas[i].gen;
        for (int j = 0; j < Individuo::col ;) {
            if((gen%2)==1){
                representation[i*Individuo::row+j]=id;
                j++;
            }
            gen=gen>>1;
            id++;
            conter++;
            if (conter>Individuo::col*Individuo::row){
                id-=conter;
                id+=j;
                j++;
                conter=0;
            }
        }
    }
//    "Create XML"
}



