//
// Created by isaac on 16/5/21.
//

#include <nlohmann/json.hpp>
#include <iostream>
#include <bitset>
#include "PZ.h"
#include "../Socket_Server.h"
#include "Individuo.h"


int PZ::row=0;
int PZ::col=0;
std::vector<int> PZ::RFit;
std::vector<int> PZ::GFit;
std::vector<int> PZ::BFit;
std::vector<int> PZ::Objective;
Generation* PZ::generations[15]{};

void PZ::run() {
    auto socket=Socket_Server::self;
    std::string Json_String=socket->recieve();
    nlohmann::basic_json<> data= nlohmann::basic_json<>::parse(Json_String);

    Objective =data["Objective"].get<std::vector<int>>();
    RFit =data["Red"].get<std::vector<int>>();
    BFit=data["Blue"].get<std::vector<int>>();
    GFit=data["Green"].get<std::vector<int>>();
    row=data["Rows"].get<int>();
    col=data["Columns"].get<int>();
    Individuo::col=col;
    Individuo::row=row;
    Fila::col=col;
    Fila::row=row;
    std::cout<<"test"<<std::endl;
    generations[0]= new Generation();
    for (int j = 0; j < 8; ++j) {
        calculate_Fitnnes(generations[0]->poblacion[j]);
    }
    generations[0]->declare_Parents();
    generations[0]->create_representation();
    for (int & j : generations[0]->representation) {
        std::cout<< j<<" ";
    }
    for (int i = 1; i < 15; ++i) {
            generations[i]=generations[i-1]->children();

        for (auto & j : generations[i]->poblacion) {
            calculate_Fitnnes(j);
        }
            generations[i]->declare_Parents();
            generations[i]->create_representation();
        for (int & j : generations[i]->representation) {
            std::cout<< j<<" ";
        }
        std::cout<<std::endl;
    }
    data=nlohmann::basic_json<>();
    data["generation"]=generations[0]->representation;
    socket->send(to_string(data));
    int position=0;
    while(true){
        auto msg=socket->recieve();
        data= nlohmann::basic_json<>::parse(msg);
        if(data.contains("action")){
            if(data["action"]=="+"){
                position=(position+1)%8;
            }else if(data["action"]=="-") {
                position=(position-1)%8;
            }else {
                return;
            }
        }
        data= nlohmann::basic_json<>();
        data["Order"]= generations[abs(position)]->representation;
        socket->send(to_string(data));
    }
}

void PZ::calculate_Fitnnes(Individuo* especimen) {
    especimen->fitnnes=0;
    for (int i = 0; i < row; ++i) {
        int r=0;
        int g=0;
        int b=0;
        unsigned int gen=especimen->chromosomas[i].gen;
        int count=0;


        for (int i = 0; i < row*col; ++i) {
            if(count/col==1){
                break;
            }
            if((gen%2)==1){
                count++;
                r+=RFit[i];
                g+=GFit[i];
                b+=BFit[i];
            }
            gen=gen>>1;
        }
        r=abs(r-Objective[i*row]);
        g=abs(g-Objective[i*row+1]);
        b=abs(b-Objective[i*row+2]);
        especimen->fitnnes+=r+g+b;

    }

}
