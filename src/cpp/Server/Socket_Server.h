//
// Created by isaac on 9/5/21.
//

#ifndef PROYECTO_II_SOCKET_SERVER_H
#define PROYECTO_II_SOCKET_SERVER_H

#include <zmqpp/socket.hpp>
#include <zmqpp/context.hpp>
#include <zmqpp/message.hpp>


class Socket_Server {
public:

    static Socket_Server* self;

    /**
     * \brief Call at ther start of the Server, No need to be called again.
     * Init and connect the socket
     */
    void init();
    zmqpp::socket * socket ;
    /**
     * \brief Not Expected to be called, because only send the string that recieve as a parameter
     * @return
     */
    std::string comunicatte(std::string);


};


#endif //PROYECTO_II_SOCKET_SERVER_H
