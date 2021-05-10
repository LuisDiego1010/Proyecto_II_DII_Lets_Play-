//
// Created by isaac on 9/5/21.
//
#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>
#include "Socket_Client.h"

void Socket_Client::Init() {
    zmqpp::context context;

    // generate a request socket
    zmqpp::socket_type type = zmqpp::socket_type::request;
    socket= new zmqpp::socket(context, type);
    socket->connect("tcp://127.0.0.1:4040");
}

std::string Socket_Client::comunicatte(std::string msg) {
    std::cout<<"[C]Sended: "<<msg;
    socket->send(msg);
    socket->receive(msg);
    std::cout<<"[C]Recieved: "<<msg;
    return msg;
}
