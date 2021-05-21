//
// Created by garroakion on 10/5/21.
//

#include "BpWindow.h"
#include "bpGameMode.h"

BpWindow::BpWindow() {}

void BpWindow::Show() {
    bpGameMode game;


    backpath = vector<int>(14*9,0);
    RenderWindow window(sf::VideoMode(1440, 998), "BP GAME");

    //Creacion de las texturas.
    Texture field;
    Texture ball;
    Texture blockers;
    Texture square;
    Texture blockersLateral;
    Texture goalLeft;
    Texture obstacule1;
    Texture obstacule2;




    //Asignacion de las imagenes
    if (!blockers.loadFromFile("src/images/blockers.png")) {

    }
    if (!goalLeft.loadFromFile("src/images/goalLeft.png")) {

    }
    if (!blockersLateral.loadFromFile("src/images/blockerslateral.png")) {

    }
    if (!field.loadFromFile("src/images/sprfield.jpg")) {

    }
    if (!obstacule1.loadFromFile("src/images/player1.png")) {

    }
    if (!obstacule2.loadFromFile("src/images/player2.png")) {

    }
    if (!ball.loadFromFile("src/images/sprball.png")) {

    }

    if (!square.loadFromFile("src/images/sprPlayer1.png")) {

    }

    //Creacion de los sprites
    Sprite fieldSprite;
    fieldSprite.setTexture(field);

    Sprite blockersLateralLeft;
    blockersLateralLeft.setTexture(blockersLateral);

    Sprite blockersLateralLeftDown;
    blockersLateralLeftDown.setTexture(blockersLateral);


    Sprite blockersLateralRight;
    blockersLateralRight.setTexture(blockersLateral);

    Sprite blockersLateralRightDown;
    blockersLateralRightDown.setTexture(blockersLateral);

    Sprite goalKLeft;
    goalKLeft.setTexture(goalLeft);

    Sprite goalKRight;
    goalKRight.setTexture(goalLeft);



    ballBackPath.setTexture(ball);
    Sprite blockerSprite;
    blockerSprite.setTexture(blockers);

    Sprite blockerSpriteDown;
    blockerSpriteDown.setTexture(blockers);



    cout<<gameModeGoals;
    setPlayers(gameModePlayers);        //Cantidad maxima 126
    displayBackpath();

    ballBackPath.setOrigin(-690, -465);
    //Blockers horizontales

    blockerSprite.setOrigin(0,0);
    blockerSpriteDown.setOrigin(0,-972);

    //Blockers laterales
    blockersLateralLeft.setOrigin(0,0);
    blockersLateralLeftDown.setOrigin(0,-658);

    blockersLateralRight.setOrigin(-1415,0);
    blockersLateralRightDown.setOrigin(-1415,-658);



    goalKLeft.setOrigin(0,-342);
    goalKRight.setOrigin(-1415,-342);



    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::Transparent);
        window.draw(fieldSprite);
        window.draw(ballBackPath);
        window.draw(blockerSprite);
        window.draw(blockersLateralLeft);
        window.draw(blockerSpriteDown);
        window.draw(blockersLateralLeftDown);
        window.draw(blockersLateralRight);
        window.draw(blockersLateralRightDown);


        window.draw(goalKRight);
        window.draw(goalKLeft);


        for (int i = 0; i < players.size(); i++) {
            if(i<players.size()/2){
                players[i].setTexture(obstacule1);
                window.draw(players[i]);
            }
            else if(i>=players.size()/2){
                players[i].setTexture(obstacule2);
                window.draw(players[i]);
            }



        }
        window.display();


    }


}


void BpWindow::setPlayers(int n) {
    //bola en la fila 5*8colum

    int obst=0;
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);

    if(n%2==1){
        obst = n+1;
        cout<< "impar"<<endl;
    }else{
        obst = n;
        cout<< "par"<<endl;
    }



    for (int i = 0; i < obst;) {

        if(i<(obst/2)){


            int x = (rand() % 7 );
            int y = (rand() % 9 );
            float xpos = -1 * 100 * x;
            float ypos = -1 * 100 * y;
            //Cuando se cumple que no esta en la misma posicion se aumenta el iterador

            if(backpath[(y*14)+x]==1){
                cout<<"Posicion igual"<<endl;

            }else{


                Sprite sprite;
                sprite.setOrigin(xpos, ypos);
                players.push_back(sprite);
                backpath[(y*14)+x]=1;
                i++;
            }
        }else{
            int x = (rand() % 7 + 7);
            int y = (rand() % 9 );
            float xpos = -1 * 100 * x;
            float ypos = -1 * 100 * y;
            //Cuando se cumple que no esta en la misma posicion se aumenta el iterador

            if(backpath[(y*14)+x]==1){
                cout<<"Posicion igual"<<endl;

            }else{


                Sprite sprite;
                sprite.setOrigin(xpos, ypos);
                players.push_back(sprite);
                backpath[(y*14)+x]=1;
                i++;
            }
        }






    }


}

void BpWindow::displayBackpath() {
    int id=0;
    for(int i = 0; i <= 9; i++){
        cout<<endl;
        for(int j = 0; j < 14; j++){

            cout<<backpath[id];
            id++;

        }
    }
}

void BpWindow::setGameModePlayers(int gameModePlayers) {
    BpWindow::gameModePlayers = gameModePlayers;
}

void BpWindow::setGameModeGoals(int gameModeGoals) {
    BpWindow::gameModeGoals = gameModeGoals;
}











