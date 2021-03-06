//
// Created by isaac on 9/5/21.
//
#include <zmq.hpp>
#include <iostream>
#include "Socket_Client.h"

void Socket_Client::Init() {
    // generate a request socket
    zmq::socket_type type = zmq::socket_type::req;
    socket= new zmq::socket_t(ctx, type);
    socket->connect("tcp://127.0.0.1:4040");
}

std::string Socket_Client::comunicatte(std::string msg) {
    zmq::message_t msg_send(msg);
    zmq::message_t msg_recieve;
    socket->send(msg_send,zmq::send_flags::none);
    std::cout<<"[C]Sended: "<<msg_send;
    socket->recv(msg_recieve);
    std::cout<<"[C]Recieved: "<<msg_recieve;
    msg=msg_recieve.to_string();
    return msg;
}

Socket_Client *Socket_Client::getSocket() {
    return self;
}