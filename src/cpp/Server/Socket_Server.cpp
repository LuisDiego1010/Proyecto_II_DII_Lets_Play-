//
// Created by isaac on 9/5/21.
//

#include "Socket_Server.h"
#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>

void Socket_Server::init() {
    std::string endpoint="tcp://*:4040";

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a reply socket
    zmqpp::socket_type type = zmqpp::socket_type::reply;
    socket =new zmqpp::socket(context, type);

    // bind to the socket
    socket->bind(endpoint);
}
std::string Socket_Server::comunicatte(std::string msg) {
    std::cout<<"[S]Recieved: "<<msg;
    socket->receive(msg);
    socket->send(msg);
    std::cout<<"[S]Sended: "<<msg;
    return msg;
}