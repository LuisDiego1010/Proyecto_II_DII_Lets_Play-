//
// Created by garroakion on 10/5/21.
//

#include "BpWindow.h"


BpWindow::BpWindow() {}

void BpWindow::Show() {

    RenderWindow window(sf::VideoMode(1440, 998), "BP GAME");
    Texture field;
    Texture obstacule1;
    Texture obstacule2;
    Texture ball;


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

    setPlayers(10);


    obstacule1Sprite.setOrigin(-50, -420);
    obstacule2Sprite.setOrigin(-1300, -420);
    ballSprite.setOrigin(-900, -1300);

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
        window.clear(Color(35, 181, 184));
        window.draw(fieldSprite);
        window.draw(obstacule1Sprite);
        window.draw(obstacule2Sprite);
        window.draw(ballSprite);
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
        float xpos = -1 * 100 * (rand() % 12 + 2);
        float ypos = -1 * 100 * (rand() % 8 + 1);
        Sprite sprite;
        sprite.setOrigin(xpos, ypos);
        players.push_back(sprite);

    }


}










