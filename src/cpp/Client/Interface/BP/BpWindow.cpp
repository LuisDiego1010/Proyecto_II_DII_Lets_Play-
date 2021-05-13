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

    setPlayers(5);



    obstacule1Sprite.setOrigin(-50, -420);
    obstacule2Sprite.setOrigin(-1300, -420);
    ballSprite.setOrigin(-900, -1300);





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
            window.draw(players[i]);
            cout <<players[i].getOrigin().x;
            cout <<players[i].getOrigin().y;

        }
        window.display();


    }


}


void BpWindow::setPlayers(int n) {
    Texture square;
    if (!square.loadFromFile("src/images/square.png")) {

    }

    for(int i=0;i<n;i++){
        Sprite sprite;
        sprite.setTexture(square);
        sprite.setColor(Color::Black);
        sprite.setOrigin(xpos(), ypos());
        players.push_back(sprite);

    }

}

float BpWindow::xpos() {
    srand((unsigned) (time(0)));
    int x = rand() % 13 + 1; // El x va con j
    float xpos = -(x * 100);
    return xpos;
}

float BpWindow::ypos() {
    srand((unsigned) (time(0)));
    int y = rand() % 9 + 1; // El y va con i
    float ypos = -(y * 100);
    return ypos;
}











