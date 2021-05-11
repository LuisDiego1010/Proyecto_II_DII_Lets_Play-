//
// Created by isaac on 9/5/21.
//

#include "Socket_Server.h"
#include <zmq.hpp>
#include <iostream>

void Socket_Server::init() {



    // generate a request socket
    zmq::socket_type type = zmq::socket_type::rep;
    socket= new zmq::socket_t(ctx, type);

    // bind to the socket
    socket->bind(endpoint);
    std::cout<<"binded";
}
std::string Socket_Server::comunicatte(std::string msg) {
    zmq::message_t msg_send(msg);
    std::cout<<"[S]Recieved: "<<msg;
    socket->recv(msg_send);
    socket->send(msg_send, zmq::send_flags::none);
    std::cout<<"[S]Sended: "<<msg;
    return msg;
}