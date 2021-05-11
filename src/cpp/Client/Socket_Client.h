//
// Created by isaac on 9/5/21.
//

#ifndef PROYECTO_II_SOCKET_SERVER_H
#define PROYECTO_II_SOCKET_H
#include <zmq.hpp>

class Socket_Client {
public:
    static Socket_Client * self;
    void Init();
    zmq::context_t ctx;
    std::string endpoint="tcp://*:4040";
    zmq::socket_t * socket;
    std::string comunicatte(std::string);

};


#endif //PROYECTO_II_SOCKET_SERVER_H
