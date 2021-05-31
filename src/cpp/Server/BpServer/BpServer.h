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
    bool Player1;

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

/**
 * calle rof the path finding logic
 */
    void PathfindingPlayer();
};


#endif //PROYECTO_II_BPSERVER_H
