
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
            Xpos = data["XBall"].get<int>();

        }
        if (data.contains("YBall")) {
            Ypos = data["YBall"].get<int>();

        } else if (data.contains("TYPE")) {
            if(data["TYPE"].get<string>()=="B"){
                data["route"] = route.backtrackingRoute(backtrackingServer, {Ypos, Xpos}, {3, 0});
            }else if (data["TYPE"].get<string>()=="P"){
                PathfindingPlayer();
            }

        }
        if(Player1){
            Player1=false;
        }else{
            Player1=true;
        }
        data = nlohmann::basic_json<>();
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
    Pathfinding player;

    Pair src=make_pair(Xpos,Ypos);

    Pair dest;
    if(Player1){
        dest=make_pair(13,3);
    }else{
        dest=make_pair(0,3);
    }

    player.aStarSearch(pathfinding, src, dest);
}

