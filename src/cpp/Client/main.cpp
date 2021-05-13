
#include <iostream>
#include "Socket_Client.h"

#include "Interface/mainWindow.h"


using namespace std;
Socket_Client * Socket_Client::self= new Socket_Client();
int main() {

    Socket_Client * socket = Socket_Client::self;
    socket->Init();
    mainWindow mainInterface;
    mainInterface.show();



    return 0;
}


