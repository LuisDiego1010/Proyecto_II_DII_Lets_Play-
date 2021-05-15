//
// Created by isaac on 9/5/21.
//

#ifndef PROYECTO_II_SOCKET_SERVER_H
#define PROYECTO_II_SOCKET_SERVER_H
#include <zmq.hpp>

class Socket_Server {
public:
    static Socket_Server* self;

    zmq::context_t ctx;
    std::string endpoint="tcp://*:4040";
    zmq::socket_t * socket;

    /**
     * \brief Call at the start of the Server, No need to be called again.
     * Init and connect the socket
     */
    void init();
    /**
     * \brief Not Expected to be called, because only send the string that recieve as a parameter
     * @return
     */
    std::string comunicatte(std::string);
    std::string recieve();
    std::string send(std::string);

};


#endif //PROYECTO_II_SOCKET_SERVER_H
