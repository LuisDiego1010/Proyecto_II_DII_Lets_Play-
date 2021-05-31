/**
  * @file BpServer.h
  * */

#ifndef PROYECTO_II_BPSERVER_H
#define PROYECTO_II_BPSERVER_H

#include <string>

using namespace std;

class BpServer {
public:

    char backtrackingServer[9][14];
    int pathfinding[9][14];
    int Xpos;
    int Ypos;


/**
* @brief Constructor of the class
*/
    BpServer();

/**
* @brief In charge of the socket call
*/
    void Run();

/**
* @brief In charge to add the client data to the backtracking matrix
*/
    void addToMatrix(string &matrix);

};


#endif //PROYECTO_II_BPSERVER_H
