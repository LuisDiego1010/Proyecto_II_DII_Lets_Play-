//
// Created by isaac on 16/5/21.
//

#include <nlohmann/json.hpp>
#include "PZ.h"
#include "../Socket_Server.h"
#include "Individuo.h"


int PZ::row=0;
int PZ::col=0;
std::vector<int> PZ::RFit;
std::vector<int> PZ::GFit;
std::vector<int> PZ::BFit;
std::vector<int> PZ::Objective;
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


}

void PZ::calculate_Fitnnes(Individuo* especimen) {
    especimen->fitnnes=0;
    for (int i = 0; i < row; ++i) {
        int r=0;
        int g=0;
        int b=0;
        int gen=especimen->chromosomas->gen;
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
        r=abs(r-Objective[row]);
        g=abs(r-Objective[row]);
        b=abs(r-Objective[row]);
        especimen->fitnnes+=r+g+b;
    }
}
