/**
  * @file Socket_Client.h
  * */


#ifndef PROYECTO_II_SOCKET_SERVER_H
#define PROYECTO_II_SOCKET_H
#include <zmq.hpp>

class Socket_Client {
public:
    static Socket_Client * self;

    static Socket_Client *getSocket();

    /**
     * \brief Initializer of the socket, create the singleton and connect to the server
     */
    void Init();
    zmq::context_t ctx;
    std::string endpoint="tcp://*:4040";
    zmq::socket_t * socket;
    /**
     * \brief send a String to server and return the server answer.
     * @return
     */
    std::string comunicatte(std::string);
};


#endif //PROYECTO_II_SOCKET_SERVER_H
