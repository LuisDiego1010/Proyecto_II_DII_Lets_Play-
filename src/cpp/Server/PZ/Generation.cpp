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
    auto Doc= new tinyxml2::XMLDocument();
    XML=Doc->NewElement("Generation");
    Doc->InsertFirstChild(XML);

    for (int i = 0; i < 11; ++i) {
        auto XML_Individuo=XML->GetDocument()->NewElement("Individuo");
        XML_Individuo->SetAttribute("number", i);
        XML->InsertEndChild(XML_Individuo);
        auto tmp=new Individuo();
        for (int j = 0; j < Individuo::row; ++j) {
            auto XML_Fila=XML->GetDocument()->NewElement("Fila");
            XML_Fila->SetAttribute("number", j);
            XML_Fila->SetText(tmp->chromosomas[j].gen);
            XML_Individuo->InsertEndChild(XML_Fila);
        }
        poblacion[i]= &*tmp;
    }
}

Generation* Generation::children() {
    auto tmpGeneration= new Generation(true);
    tmpGeneration->Mother= nullptr;
    tmpGeneration->Father= nullptr;
    tmpGeneration->representation=std::vector<int>(Individuo::col*Individuo::col, 0);
    auto Doc= new tinyxml2::XMLDocument();
    tmpGeneration->XML=Doc->NewElement("Generation");
    Doc->InsertFirstChild(tmpGeneration->XML);

    for (int i = 0; i < 11; ++i) {
        auto XML_Individuo=tmpGeneration->XML->GetDocument()->NewElement("Individuo");
        XML_Individuo->SetAttribute("number", i);
        tmpGeneration->XML->InsertEndChild(XML_Individuo);

        Individuo* tmp= nullptr;
        tmp=new Individuo(this->poblacion[rand()%11],this->poblacion[rand()%11]);
        for (int j = 0; j < Individuo::row; ++j) {
            auto XML_Fila=tmpGeneration->XML->GetDocument()->NewElement("Fila");
            XML_Fila->SetAttribute("number", j);
            XML_Fila->SetText(tmp->chromosomas[j].gen);
            XML_Individuo->InsertEndChild(XML_Fila);
        }
        tmpGeneration->poblacion[i]= tmp;
    }
    return tmpGeneration;
}

Generation* Generation::mutation() {
    auto tmpGeneration= new Generation(true);
    tmpGeneration->Mother= nullptr;
    tmpGeneration->Father= nullptr;
    tmpGeneration->representation=std::vector<int>(Individuo::col*Individuo::col, 0);
    auto Doc= new tinyxml2::XMLDocument();
    tmpGeneration->XML=Doc->NewElement("Generation");
    Doc->InsertFirstChild(tmpGeneration->XML);

    for(int i=0;i<11;i++) {
        auto XML_Individuo=tmpGeneration->XML->GetDocument()->NewElement("Individuo");
        XML_Individuo->SetAttribute("number", i);
        tmpGeneration->XML->InsertEndChild(XML_Individuo);

        Individuo* tmp= nullptr;
        if((rand()%2)==1){
            tmp=new Individuo(Mother,this->poblacion[rand()%11]);
        }else {
            auto mutation= new Individuo();
            tmp=new Individuo(mutation,this->poblacion[rand()%11]);
        }
        for (int j = 0; j < Individuo::row; ++j) {
            auto XML_Fila=tmpGeneration->XML->GetDocument()->NewElement("Fila");
            XML_Fila->SetAttribute("number", j);
            XML_Fila->SetText(tmp->chromosomas[j].gen);
            XML_Individuo->InsertEndChild(XML_Fila);
        }
        tmpGeneration->poblacion[i]= tmp;
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
    std::string stringRepresentation;
    for (int i = 0; i < Individuo::row; ++i) {
        int id=0;
        int conter=0;
        unsigned int gen=Mother->chromosomas[i].gen;
        for (int j = 0; j < Individuo::col ;) {
            if((gen%2)==1){
                representation[i*Individuo::row+j]=id;
                j++;
                stringRepresentation+=" "+std::to_string(id);
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
    auto XML_Representacion=XML->GetDocument()->NewElement("Representacion");
    XML_Representacion->SetText(stringRepresentation.data());
    XML->InsertEndChild(XML_Representacion);
}

void Generation::mutate() {
    int sawp=0;
    while(sawp==0){
    sawp =rand()%Individuo::row;}
    Fila *tmp= &Mother->chromosomas[0];
    Mother->chromosomas[0]=Mother->chromosomas[sawp];
    Mother->chromosomas[sawp]=*tmp;
}





