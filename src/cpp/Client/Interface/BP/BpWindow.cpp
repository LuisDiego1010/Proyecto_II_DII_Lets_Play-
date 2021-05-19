//
// Created by garroakion on 10/5/21.
//

#include "BpWindow.h"


BpWindow::BpWindow() {}

void BpWindow::Show() {

    backpath = vector<int>(14*9,0);
    RenderWindow window(sf::VideoMode(1440, 998), "BP GAME");
    Texture field;
    Texture obstacule1;
    Texture obstacule2;
    Texture ball;
    Texture blockers;




    if (!blockers.loadFromFile("src/images/blockers.png")) {

    }
    if (!field.loadFromFile("src/images/sprfield.jpg")) {

    }
    if (!obstacule1.loadFromFile("src/images/sprPlayer1.png")) {

    }

    if (!obstacule2.loadFromFile("src/images/sprPlayer2.png")) {

    }
    if (!ball.loadFromFile("src/images/sprball.png")) {

    }

    Sprite fieldSprite;
    fieldSprite.setTexture(field);

    Sprite obstacule1Sprite;
    obstacule1Sprite.setTexture(obstacule1);

    Sprite obstacule2Sprite;
    obstacule2Sprite.setTexture(obstacule2);

    Sprite ballSprite;
    ballSprite.setTexture(ball);

    Sprite blockerSprite;
    blockerSprite.setTexture(blockers);

    Sprite blockerSpriteDown;
    blockerSpriteDown.setTexture(blockers);

    setPlayers(10);


    obstacule1Sprite.setOrigin(-50, -420);
    obstacule2Sprite.setOrigin(-1300, -420);
    ballSprite.setOrigin(-460, -500);
    blockerSprite.setOrigin(0,0);
    blockerSpriteDown.setOrigin(0,-972);
  //  blockerSpriteDown.setColor(Color(255, 0, 0));
  //  blockerSprite.setColor(Color(255, 0, 0));

    Texture square;
    if (!square.loadFromFile("src/images/sprPlayer1.png")) {

    }


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
        window.draw(ballSprite);
        window.draw(obstacule1Sprite);
        window.draw(obstacule2Sprite);
        window.draw(ballSprite);
        window.draw(blockerSprite);
        window.draw(blockerSpriteDown);

        for (int i = 0; i < players.size(); i++) {
            players[i].setTexture(square);
            window.draw(players[i]);


        }
        window.display();


    }


}


void BpWindow::setPlayers(int n) {

    time_t seconds;
    time(&seconds);
    srand((unsigned) seconds);


    for (int i = 0; i < n; i++) {
        int x = (rand() % 12 + 2);
        int y = (rand() % 8 + 1);
        float xpos = -1 * 100 * x;
        float ypos = -1 * 100 * y;

        Sprite sprite;
        sprite.setOrigin(xpos, ypos);
        players.push_back(sprite);
        backpath[x*y]=-1;

    }
    int id=0;
    for(int i = 0; i < 9; i++){
        cout<<endl;
        for(int j = 0; i < 14; j++){

            cout<<backpath[id];
            id++;

        }
    }


}










