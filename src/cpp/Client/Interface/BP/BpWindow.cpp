//
// Created by garroakion on 10/5/21.
//
#include "Backtracking.h"
#include "BpWindow.h"
#include "bpGameMode.h"
#include "../InputBox.h"

BpWindow::BpWindow() {}

void BpWindow::Show() {




    bpGameMode game;


    setBacktracking();



    cout<<endl;



    RenderWindow window(sf::VideoMode(1700, 998), "BP GAME");

    //Creacion de las texturas.
    Texture field;
    Texture ball;
    Texture blockers;
    Texture square;
    Texture blockersLateral;
    Texture goalLeft;
    Texture obstacule1;
    Texture obstacule2;
    Texture leaderboard;
    Texture btnNextPlayer;



    if(!btnNextPlayer.loadFromFile("src/images/btn/nextPlayer.png")){
        cout<<"Error to charge image";
    }

    //Asignacion de las imagenes
    if (!leaderboard.loadFromFile("src/images/leaderboard.png")) {

    }

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
    /*----------------NextPlayerButton-----------------*/
    Sprite btnNextPlayerSprite;
    btnNextPlayerSprite.setTexture(btnNextPlayer);
    btnNextPlayerSprite.setOrigin(-1480,-750);

    /*----------------Field-----------------*/
    Sprite fieldSprite;
    fieldSprite.setTexture(field);

    /*----------------Leaderboard-----------------*/
    Sprite leaderboardSprite;
    leaderboardSprite.setTexture(leaderboard);
    leaderboardSprite.setOrigin(-1443, 0);


    /*----------------Blockers-----------------*/
    Sprite blockersLateralLeft;
    blockersLateralLeft.setTexture(blockersLateral);

    Sprite blockersLateralLeftDown;
    blockersLateralLeftDown.setTexture(blockersLateral);

    Sprite blockersLateralRight;
    blockersLateralRight.setTexture(blockersLateral);

    Sprite blockersLateralRightDown;
    blockersLateralRightDown.setTexture(blockersLateral);

    Sprite blockerSpriteDown;
    blockerSpriteDown.setTexture(blockers);

    Sprite blockerSprite;
    blockerSprite.setTexture(blockers);

    blockerSprite.setOrigin(0, 0);
    blockerSpriteDown.setOrigin(0, -972);

    blockersLateralLeft.setOrigin(0, 0);
    blockersLateralLeftDown.setOrigin(0, -658);

    blockersLateralRight.setOrigin(-1415, 0);
    blockersLateralRightDown.setOrigin(-1415, -658);



    /*----------------Goals-----------------*/
    goalKLeft.setTexture(goalLeft);
    goalKRight.setTexture(goalLeft);

    goalKLeft.setOrigin(0, -342);
    goalKRight.setOrigin(-1415, -342);



    /*----------------Ball-----------------*/
    ballBackPath.setTexture(ball);
   // ballBackPath.setOrigin(-690 + 80, -465 + 36);
    ballBackPath.setOrigin(-200, -400);



    /*----------------Game Init-----------------*/
    setPlayers(gameModePlayers);
    cout<<endl;
    displayBacktracking();
    cout<<endl;




    while (window.isOpen()) {


        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                if (btnNextPlayerSprite.getGlobalBounds().contains(translated_pos)) {
                    backtracking[getPositionYBall()][getPositionXBall()] = '1';
                    backtracking[getPositionYGoalPlayer()][getPositionXGoalPlayer()] = '1';
                    Backtracking back;
                    cout<<endl;
                    cout<<getPositionYBall()<<" "<<getPositionXBall()<<endl;
                    cout<<getPositionYGoalPlayer()<<" "<<getPositionXGoalPlayer()<<endl;
                    back.pathMoves(backtracking, {getPositionYBall(),getPositionXBall()},{getPositionYGoalPlayer(),getPositionXGoalPlayer()});
                    cout<<endl;
                }
            }


        }

        window.clear(Color::Transparent);
        window.draw(fieldSprite);
        window.draw(ballBackPath);
        window.draw(blockerSprite);
        window.draw(leaderboardSprite);
        window.draw(btnNextPlayerSprite);
        window.draw(blockersLateralLeft);
        window.draw(blockerSpriteDown);
        window.draw(blockersLateralLeftDown);
        window.draw(blockersLateralRight);
        window.draw(blockersLateralRightDown);


        window.draw(goalKRight);
        window.draw(goalKLeft);


        for (int i = 0; i < players.size(); i++) {

            if (i < players.size() / 2) {
                players[i].setTexture(obstacule1);
                window.draw(players[i]);
            } else if (i >= players.size() / 2) {
                players[i].setTexture(obstacule2);
                window.draw(players[i]);
            }


        }
        window.display();


    }


}


void BpWindow::setPlayers(int n) {


    int obst = 0;
    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);

    if (n % 2 == 1) {
        obst = n + 1;
    } else {
        obst = n;
    }


    for (int i = 0; i < obst;) {



        if (i < (obst / 2)) {


            int x = (rand() % 7);
            int y = (rand() % 9);
            float xpos = -1 * 100 * x;
            float ypos = -1 * 100 * y;
            //Cuando se cumple que no esta en la misma posicion se aumenta el iterador

            if (backtracking[y][x] == '2') {
                cout << "Posicion de la bola" << endl;
            }
            if (backtracking[y][x] == '0') {
                cout << "Posicion igual" << endl;

            } else {


                Sprite sprite;
                sprite.setOrigin(xpos, ypos);
                players.push_back(sprite);
                backtracking[y][x] = '0';
                i++;
            }
        } else {
            int x = (rand() % 7 + 7);
            int y = (rand() % 9);
            float xpos = -1 * 100 * x;
            float ypos = -1 * 100 * y;
            //Cuando se cumple que no esta en la misma posicion se aumenta el iterador
            if (backtracking[y][x] == '2') {
                cout << "Posicion de la bola" << endl;
            }
            if (backtracking[y][x] == '0') {
                cout << "Posicion igual" << endl;

            } else {


                Sprite sprite;
                sprite.setOrigin(xpos, ypos);
                players.push_back(sprite);
                backtracking[y][x] = '0';
                i++;
            }
        }


    }


}






/*----------------Position Ball-----------------*/
int BpWindow::getPositionXBall() {
    return -(int) (ballBackPath.getOrigin().x / 100);
}

int BpWindow::getPositionYBall() {
    return -(int) (ballBackPath.getOrigin().y / 100);
}

/*----------------Position Goal Player-----------------*/
int BpWindow::getPositionXGoalPlayer() {
    return -(int) (goalKLeft.getOrigin().x / 100);
}

int BpWindow::getPositionYGoalPlayer() {
    return -(int) (goalKLeft.getOrigin().y / 100);
}

/*----------------Setters goals and players-----------------*/
void BpWindow::setGameModePlayers(int gameModePlayers) {
    BpWindow::gameModePlayers = gameModePlayers;
}

void BpWindow::setGameModeGoals(int gameModeGoals) {
    BpWindow::gameModeGoals = gameModeGoals;
}


/*----------------Backtracking-----------------*/
void BpWindow::displayBacktracking() {
    for(int i =0; i<9;i++){
        cout<<endl;
        for (int j=0 ;j<14;j++){
            cout<<backtracking[i][j];
        }
    }
}

void BpWindow::setBacktracking() {
    for(int i =0; i<9;i++){
        for (int j=0 ;j<14;j++){
            backtracking[i][j]= '1';
        }
    }
}



























