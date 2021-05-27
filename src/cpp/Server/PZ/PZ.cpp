//
// Created by isaac on 16/5/21.
//

#include <nlohmann/json.hpp>
#include <iostream>
#include "PZ.h"
#include "../Socket_Server.h"
#include "Individuo.h"
#include <tinyxml2.h>
#include <ctime>

int PZ::row=0;
int PZ::col=0;
std::vector<int> PZ::RFit;
std::vector<int> PZ::GFit;
std::vector<int> PZ::BFit;
std::vector<int> PZ::Objective;
Generation* PZ::generations[25]{};

void PZ::run() {
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);

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

    int max=0;
    for (int i = 0; i < col*row; ++i) {
        max=max|1<<i;

    }
    Individuo::max=max;

    std::cout<<max<<std::endl;


    generations[0]= new Generation();
    auto individuo=generations[0]->XML->FirstChildElement();

    for (int j = 0; j < 11; ++j) {
        calculate_Fitnnes(generations[0]->poblacion[j]);
        if(individuo!= nullptr){
            individuo=individuo->NextSiblingElement();
            if(individuo!= nullptr){
                individuo->SetAttribute("Fitness", std::to_string(j).data());
            }
        }

    }
    generations[0]->declare_Parents();
    generations[0]->create_representation();
    for (int & j : generations[0]->representation) {
        std::cout<< j<<" ";
    }
    std::cout<< std::endl;
    generations[0]->XML->GetDocument()->SaveFile("Test.xml");

    for (int i = 1; i < 25; ++i) {
        if(i>3){
            if(generations[i-1]->representation==generations[i-2]->representation){
                generations[i]=generations[0]->mutation();
                generations[i]->declare_Parents();
                generations[i]->mutate();
            }else{
                generations[i]=generations[i-1]->children();
            }
        }else{
            generations[i]=generations[i-1]->children();
        }
        individuo=generations[i]->XML->FirstChildElement();
        for (int j=0;j<11;j++) {
            calculate_Fitnnes(generations[i]->poblacion[j]);
            if(individuo!= nullptr){
                individuo=individuo->NextSiblingElement();
                if(individuo!= nullptr){
                    individuo->SetAttribute("Fitness", std::to_string(j).data());
                }
            }
        }
            generations[i]->declare_Parents();
            generations[i]->create_representation();
        for (int & j : generations[i]->representation) {
            std::cout<< j<<" ";
        }
        std::cout<<" ;"<< generations[i]->Mother->fitnnes<<"=Fitness ";

        std::cout<<std::endl;
        time_t timeNow=time(nullptr);
        char* Localtime=ctime(&timeNow);
        std::string FileName="XML/"+std::to_string(i)+":"+ Localtime+".xml";
        generations[i]->XML->Parent()->GetDocument()->SaveFile(FileName.data());

    }
    data=nlohmann::basic_json<>();
    data["generation"]=generations[0]->representation;
    socket->send(to_string(data));
    int position=0;
//    comunicon con el cliente
    while(true){
        auto msg=socket->recieve();
        data= nlohmann::basic_json<>::parse(msg);
        if(data.contains("action")){
            if(data["action"]=="+"){
                position=(position+1)%25;
            }else if(data["action"]=="-") {
                position=(position-1)%25;
            }else {
                break;
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
                r+=RFit[i]-count;
                g+=GFit[i]-count;
                b+=BFit[i]-count;
                count++;
            }
            gen=gen>>1;
        }
        r=abs(r-Objective[i*row]);
        g=abs(g-Objective[i*row+1]);
        b=abs(b-Objective[i*row+2]);
        especimen->fitnnes+=r+g+b;

    }

}
