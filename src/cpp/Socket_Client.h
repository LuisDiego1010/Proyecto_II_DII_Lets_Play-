//
// Created by isaac on 9/5/21.
//

#ifndef PROYECTO_II_SOCKET_SERVER_H
#define PROYECTO_II_SOCKET_H
#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>

class Socket_Client {
public:
    static Socket_Client * self;
    void Init();
    std::string endpoint="tcp://*:4040";
    zmqpp::socket * socket;
    std::string comunicatte(std::string);

};


#endif //PROYECTO_II_SOCKET_SERVER_H
