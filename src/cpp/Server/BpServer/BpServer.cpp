
#include "BpServer.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <bitset>
#include "../Socket_Server.h"
#include <bits/stdc++.h>
#include "Backtracking.h"

using namespace std;

void BpServer::Run() {
    auto socket = Socket_Server::self;
    std::string Json_String;
    nlohmann::basic_json<> data;
    string matrix;
    Backtracking route;

    while (true) {
        auto msg = socket->recieve();
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

        } else if (data.contains("pathfinding")) {
            //pahtfinding
        }
        data = nlohmann::basic_json<>();
        data["route"] = route.pathMoves(backtrackingServer, {Ypos, Xpos}, {3, 0});
        socket->send(to_string(data));

        break;

    }


}


void BpServer::addToMatrix(string &matrix) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 14; j++) {
            backtrackingServer[i][j] = *matrix.data();
            matrix.pop_back();
        }
    }

}

BpServer::BpServer() {

}


