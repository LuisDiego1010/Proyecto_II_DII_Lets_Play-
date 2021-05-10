//
// Created by isaac on 9/5/21.
//

#include "Socket.h"

void Socket::Init() {
    zmqpp::context context;

    // generate a request socket
    zmqpp::socket_type type = zmqpp::socket_type::request;
    socket= new zmqpp:: socket(context, type);
    socket->connect("tcp://127.0.0.1:4040");
}

std::string Socket::comunicatte(std::string msg) {
    std::cout<<"[C]Sended: "<<msg;
    socket->send(msg);
    socket->receive(msg);
    std::cout<<"[C]Recieved: "<<msg;
    return msg;
}
