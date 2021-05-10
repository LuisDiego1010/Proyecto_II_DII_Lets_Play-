//
// Created by isaac on 9/5/21.
//

#ifndef PROYECTO_II_SOCKET_H
#define PROYECTO_II_SOCKET_H

#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>

class Socket {
public:
    static void init();
    static zmqpp::socket * socket ;
    static std::string comunicatte(std::string);


};


#endif //PROYECTO_II_SOCKET_H
