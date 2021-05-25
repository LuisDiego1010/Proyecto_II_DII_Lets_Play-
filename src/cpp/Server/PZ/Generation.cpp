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
    for (int i = 0; i < 11; ++i) {
        auto tmp=new Individuo();
        poblacion[i]= &*tmp;
    }
}

Generation* Generation::children() {
    auto tmpGeneration= new Generation(true);
    tmpGeneration->Mother= nullptr;
    tmpGeneration->Father= nullptr;
    tmpGeneration->representation=std::vector<int>(Individuo::col*Individuo::col, 0);
    for (int i = 0; i < 11; ++i) {
        Individuo* tmp= nullptr;
        tmp=new Individuo(this->poblacion[rand()%11],this->poblacion[rand()%11]);
        tmpGeneration->poblacion[i]= tmp;
    }
    return tmpGeneration;
}

Generation* Generation::mutation() {
    auto tmpGeneration= new Generation(true);
    tmpGeneration->Mother= nullptr;
    tmpGeneration->Father= nullptr;
    tmpGeneration->representation=std::vector<int>(Individuo::col*Individuo::col, 0);
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);

    for (auto & i : tmpGeneration->poblacion) {

        Individuo* tmp= nullptr;
        if((rand()%2)==1){
            auto mutation= new Individuo();
            tmp=new Individuo(Mother,this->poblacion[rand()%11]);
        }else {
            auto mutation= new Individuo();
            tmp=new Individuo(mutation,this->poblacion[rand()%11]);
        }
        i= tmp;
    }
    return tmpGeneration;
}


void Generation::declare_Parents() {
    Mother=poblacion[0];
    Father=poblacion[1];
    for (int i = 1; i < 11; ++i) {
        int newFitness=poblacion[i]->fitnnes;
        int MotherFitness=Mother->fitnnes;
        if(newFitness<=MotherFitness){
            if(newFitness!=MotherFitness){
            Father=&*Mother;}

            Mother=&*poblacion[i];
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

void Generation::mutate() {
    int sawp;
    while(sawp==0){
    sawp =rand()%Individuo::row;}
    Fila *tmp= &Mother->chromosomas[0];
    Mother->chromosomas[0]=Mother->chromosomas[sawp];
    Mother->chromosomas[sawp]=*tmp;
}





