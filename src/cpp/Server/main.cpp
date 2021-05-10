//
// Created by isaac on 9/5/21.
//

#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <nlohmann/json.hpp>
#include "Socket.h"

int main(int argc, char *argv[]){

    Socket::init();
    std::string msg;
    Socket::socket->receive(msg);

    // Call to engine loops
    nlohmann::json Json = nlohmann::json::parse(msg);
    std::cout << Json <<std::endl;
    if (Json.contains("Game")) {
        if (Json["Game"] == "BP") {
            //call to Game Engine
        } else if (Json["Game"] == "Genetic") {
            //call to Genetic Engine
        }
    }else if(msg=="/Stop"){
        return -1;
    }

}