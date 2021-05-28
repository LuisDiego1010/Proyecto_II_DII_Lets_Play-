//
// Created by garroakion on 27/5/21.
//

#ifndef PROYECTO_II_BPSERVER_H
#define PROYECTO_II_BPSERVER_H

#include <string>

using namespace std;
class BpServer {
public:
    BpServer();
    char backtrackingServer[9][14];
    int Xpos;
    int Ypos;
    void Run();
    void addToMatrix(string &matrix);

};


#endif //PROYECTO_II_BPSERVER_H
