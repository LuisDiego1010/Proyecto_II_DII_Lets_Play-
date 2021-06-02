
#include "BpServer.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <bitset>
#include "../Socket_Server.h"
#include <bits/stdc++.h>
#include "Backtracking.h"
#include "Pathfinding.h"

using namespace std;

void BpServer::Run() {
    auto socket = Socket_Server::self;
    std::string Json_String;
    nlohmann::basic_json<> data;
    string matrix;
    Backtracking route;
    Player1=true;
    while (true) {
        auto msg = socket->recieve();
        if(msg.empty()){
            break;
        }
        data = nlohmann::basic_json<>::parse(msg);
        if (data.contains("matrix")) {
            matrix = data["matrix"].get<string>();
            addToMatrix(matrix);
        }
        if (data.contains("XBall")) {
            column = data["XBall"].get<int>();

        }
        if (data.contains("YBall")) {
            row = data["YBall"].get<int>();

        }
        if (data.contains("TYPE")) {
            if(data["TYPE"].get<string>()==string("B")){
                data = nlohmann::basic_json<>();
                data["route"] = route.backtrackingRoute(backtrackingServer, {row, column}, {3, 0});
               // PathfindingPlayer();
                data["routeX"]=PlayerPath.AnswersX;
                data["routeY"]=PlayerPath.AnswersY;
            }else if (data["TYPE"].get<string>()==string("P")){
                data = nlohmann::basic_json<>();
                PathfindingPlayer();
                data["routeX"]=PlayerPath.AnswersX;
                data["routeY"]=PlayerPath.AnswersY;
            }

        }
        if(Player1){
            Player1=false;
        }else{
            Player1=true;
        }
        socket->send(to_string(data));

    }


}


void BpServer::addToMatrix(string &matrix) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 14; j++) {
            char tmp;
            tmp=*matrix.data();
            backtrackingServer[i][j] = matrix[i*9+j];
            pathfinding[i][j] = (int)matrix[i*9+j]-48;

        }
    }

}

BpServer::BpServer() {

}

void BpServer::PathfindingPlayer(){

    PlayerPath= Pathfinding();
    Pair src=make_pair(row, column);

    Pair dest;
    if(Player1){
        dest=make_pair(3,13);
    }else{
        dest=make_pair(3,0);
    }
    PlayerPath.findRoute(pathfinding, src, dest);
    cout<<endl;

//    for (int i = 13; i > 0; --i) {
//        cout<<PlayerPath.AnswersX[i]<<",";
//        cout<<PlayerPath.AnswersY[i]<<endl;
//    }

}

