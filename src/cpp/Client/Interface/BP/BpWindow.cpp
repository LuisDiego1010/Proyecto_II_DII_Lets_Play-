//
// Created by garroakion on 10/5/21.
//
#include <nlohmann/json.hpp>
#include "BpWindow.h"
#include "bpGameMode.h"
#include "../InputBox.h"
#include "../../Socket_Client.h"


#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <string>

BpWindow::BpWindow() {}

void BpWindow::Show() {

    Socket_Client * socket = Socket_Client::self;
    bpGameMode game;
    setBacktracking();
    cout<<endl;

    window = new RenderWindow (sf::VideoMode(1700, 998), "BP GAME");
    window->setFramerateLimit(120);

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

    if (!font.loadFromFile("src/cpp/Client/Interface/Fonts/Ubuntu-Bold.ttf")) {
        cout << "Error to charge font";
    }

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
    btnNextPlayerSprite.setOrigin(-40,-40);

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
    //ballBackPath.setOrigin(-690 + 80, -465 + 36);
    ballBackPath.setPosition(725,494);
    cout<<"ORIGIN X BALL POS: "<<ballBackPath.getPosition().x<<endl;
    cout<<"ORIGIN Y BALL POS: "<<ballBackPath.getPosition().y<<endl;
    Vector2f m_center=sf::Vector2f(100.f, 100.f);


    /*----------------Game Init-----------------*/
    setPlayers(gameModePlayers);
    cout<<endl;
    displayBacktracking();
    cout<<endl;

    /*-----Comunicatee standars------*/
    nlohmann::json gameData;


    /*----Goals----*/
    n_goalLeft=0;
    n_goalRight=0;

    while (window->isOpen()) {
        dt = dt_clock.restart().asSeconds();
        Event event;
        collisionsBoards();
        collisionGoal();
        ballmove();

        auto mouse_pos = sf::Mouse::getPosition(*window); // Mouse position relative to the window
        auto translated_pos = window->mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                window->close();
            }
            else if (event.type == Event::MouseButtonPressed) {
                /*if (event.mouseButton.button== sf::Mouse::Right){
                    updateDirectionLine();
                }*/

                if (btnNextPlayerSprite.getGlobalBounds().contains(translated_pos)) {
                    backtracking[getPositionYBall()][getPositionXBall()] = '1';
                    backtracking[getPositionYGoalPlayer()][getPositionXGoalPlayer()] = '1';
                    cout<<endl;

                    gameData=nlohmann::basic_json<>();
                    string backtrackingString;
                    backtrackingString = backtracking[0];
                    gameData["matrix"]=backtrackingString;
                    gameData["XBall"]=getPositionXBall();
                    gameData["YBall"]=getPositionYBall();
                    cout<<to_string(gameData)<<" :String of nacktracking";
                    string JsonServer;
                    JsonServer= socket->comunicatte(to_string(gameData));
                    gameData=nlohmann::basic_json<>::parse(JsonServer);
                    cout<<endl;

                    if(gameData.contains("route")){
                      route = gameData["route"].get<string>();
                    }else{
                        cout<<"Error"<<endl;
                    }




                }


                if (event.MouseMoved){
                  m_mouse.x=event.mouseMove.x;
                  m_mouse.y=event.mouseMove.y;
                }
            }


        }
        window->clear(Color::Transparent);
        window->draw(fieldSprite);
        window->draw(ballBackPath);
        window->draw(blockerSprite);
        window->draw(leaderboardSprite);
        window->draw(btnNextPlayerSprite);
        window->draw(blockersLateralLeft);
        window->draw(blockerSpriteDown);
        window->draw(blockersLateralLeftDown);
        window->draw(blockersLateralRight);
        window->draw(blockersLateralRightDown);


        window->draw(goalKRight);
        window->draw(goalKLeft);
        if(direction != nullptr){
//            window.draw(*direction);
        }

        for (int i = 0; i < players.size(); i++) {

            if (i < players.size() / 2) {
                players[i].setTexture(obstacule1);
                window->draw(players[i]);
                collsionObstacles1(players[i]);
            } else if (i >= players.size() / 2) {
                players[i].setTexture(obstacule2);
                collsionObstacles2(players[i]);
                window->draw(players[i]);
            }
        }
        window->display();
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

int BpWindow::setGameModeGoals(int gameModeGoals) {
    BpWindow::gameModeGoals = gameModeGoals;
    return gameModeGoals;
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

void BpWindow::ballmove() {

    //velocity.x=velocity.x*0.9999;
    //velocity.y=velocity.y*0.9999;
    const float movementSpeed=1.f;
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        velocity.y += -movementSpeed * (dt);
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        velocity.y += movementSpeed * (dt);
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        velocity.x += -movementSpeed * (dt);
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        velocity.x += movementSpeed * (dt);
    }
    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        velocity.x=0;
        velocity.y=0;
    }
    ballBackPath.move(velocity);

}
void BpWindow::updateDirectionLine() {
        auto tmp = direction;
        direction=nullptr;
        delete tmp;

        sf::Vector2f distance = (m_mouse - ballBackPath.getOrigin());
        float distanceBetween = sqrt(distance.x*distance.x + distance.y*distance.y);
        sf::Vector2f invert = distance / distanceBetween;
        sf::Color directionColor = sf::Color(255, (255 - ((int)distanceBetween/2)%255), 0);
        if (distanceBetween > 510) {
            directionColor = sf::Color::Red;
        }
        direction = new Line(ballBackPath.getOrigin().x, ballBackPath.getOrigin().y,
                             ballBackPath.getOrigin().x - distanceBetween * invert.x,
                             ballBackPath.getOrigin().y - distanceBetween * invert.y, directionColor);

}

bool BpWindow::checkCollisionPoint(const sf::Vector2f& mouse)
{
    float posxBall=ballBackPath.getOrigin().x;
    float posyBall=ballBackPath.getOrigin().y;
    float x_mouse = mouse.x;
    float y_mouse = mouse.y;
    if ( ((x_mouse - posxBall)*(x_mouse - posxBall) +
          (y_mouse - posyBall)*(y_mouse - posyBall)) <=70)
    {
        cout<<"FUNCIONA";
        return true;
    }
    return false;
}

void BpWindow::collisionsBoards(){
    //Collision screen
    //Left collision
    if (ballBackPath.getPosition().x < 0.f)
        ballBackPath.setPosition(0.f, ballBackPath.getPosition().y);
    //Top collision
    if (ballBackPath.getPosition().y < 0.f)
        ballBackPath.setPosition(ballBackPath.getPosition().x, 0.f);
    //Right collision
    if (ballBackPath.getPosition().x + ballBackPath.getGlobalBounds().width > 1450)
        ballBackPath.setPosition(1450 - ballBackPath.getGlobalBounds().width, ballBackPath.getPosition().y);
    //Bottom collision
    if (ballBackPath.getPosition().y + ballBackPath.getGlobalBounds().height > 998)
        ballBackPath.setPosition(ballBackPath.getPosition().x, 998 - ballBackPath.getGlobalBounds().height);
}

void BpWindow::collsionObstacles1(Sprite player){
    if (Collision::PixelPerfectTest(ballBackPath,player)){
        ballBackPath.move(-velocity);
    }
}

void BpWindow::collsionObstacles2(Sprite player){
    if (Collision::PixelPerfectTest(ballBackPath,player)){
        ballBackPath.move(-velocity);
    }
}

bool BpWindow::collisionGoal(){
    if (Collision::PixelPerfectTest(ballBackPath,goalKRight)){
        n_goalLeft++;
        cout<<"GOAL LEFT"<<endl;
        cout<<"GOALS LEFT: "<<n_goalLeft<<endl;
        if (n_goalLeft>= gameModeGoals){
            window->close();
            GameOver("PLAYER 1");
        }
        ballBackPath.setPosition(725,494);
        goalLeft= true;
        velocity.x=0;
        velocity.y=0;
        ballBackPath.move(-velocity);
        return goalLeft;
    }
    if (Collision::PixelPerfectTest(ballBackPath,goalKLeft)){
        n_goalRight++;
        cout<<"GOAL RIGHT"<<endl;
        cout<<"GOALS RIGHT: "<<n_goalRight<<endl;
        if (n_goalRight>= gameModeGoals){
            window->close();
            GameOver("PLAYER 2");
        }
        ballBackPath.setPosition(725,494);
        goalRight= true;
        velocity.x=0;
        velocity.y=0;
        ballBackPath.move(-velocity);
        return goalRight;
    }
}

void BpWindow::GameOver(string Player) {
    RenderWindow windowOver(sf::VideoMode(1200, 800), "GAME OVER");
    sf::Text text;

    text.setFont(font);
    text.setString("GAME OVER");
    text.setCharacterSize(100); // in pixels, not points!
    text.setFillColor(sf::Color::White);
    text.setPosition(300, 110);

    sf::Text atext;
    atext.setFont(font);
    atext.setString(Player + " WINS");
    atext.setCharacterSize(105); // in pixels, not points!
    atext.setFillColor(sf::Color::White);
    atext.setPosition(275, 310);


    BpWindow bpWindow;

    while (windowOver.isOpen()) {
        Event event;
        windowOver.clear();
        auto mouse_pos = sf::Mouse::getPosition(windowOver); // Mouse position relative to the window

        while (windowOver.pollEvent(event)) {
            if (event.type == Event::Closed) {
                windowOver.close();
            }
            windowOver.clear(Color(35, 181, 184));
            windowOver.draw(text);
            windowOver.draw(atext);
            windowOver.display();
        }
    }
}
