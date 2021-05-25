//
// Created by isaac on 9/5/21.
//

#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <nlohmann/json.hpp>
#include "Socket_Server.h"
#include "PZ/PZ.h"

Socket_Server* Socket_Server::self= new Socket_Server();



int main(int argc, char *argv[]){
    std::cout<<"init socket";

    auto socket=Socket_Server::self;
    socket->init();
    std::string msg;
    std::cout<<"Socket inited";
    msg= socket->recieve();

    nlohmann::json Json = nlohmann::json::parse(msg);
    std::cout << Json <<std::endl;

    if (Json.contains("Game")) {
        if (Json["Game"] == "BP") {
            socket->send("connectect to BP");
            //call to Game Engine
        } else if (Json["Game"] == "Genetic") {
            socket->send("connectect to Genetic");
            auto Pz=PZ();
            Pz.run();
            //call to Genetic Engine
        }
    }else if(msg=="/Stop"){
        return -1;
    }

}