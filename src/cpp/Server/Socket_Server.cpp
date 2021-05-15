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
    socket->recv(msg_send);
    std::cout<<"[S]Recieved: "<<msg;
    socket->send(msg_send, zmq::send_flags::none);
    std::cout<<"[S]Sended: "<<msg;
    return msg;
}
std::string Socket_Server::recieve() {
    zmq::message_t msg;
    socket->recv(msg);
    std::cout<<"[S]Recieved: "<<msg.to_string();
    return msg.to_string();
}

std::string Socket_Server::send(std::string) {
    zmq::message_t msg;
    socket->send(msg, zmq::send_flags::none);
    std::cout<<"[S]Sended: "<<msg.to_string();
    return msg.to_string();
}