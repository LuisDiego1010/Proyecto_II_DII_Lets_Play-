//
// Created by garroakion on 10/5/21.
//

#include "puzzleGameMode.h"
#include "PuzzleWindow.h"
#include "mainWindow.h"

puzzleGameMode::puzzleGameMode() {}

void puzzleGameMode::show() {
    sf::Font font;
    if (!font.loadFromFile("src/cpp/Client/Interface/Fonts/Ubuntu-Bold.ttf"))
    {
        cout<<"Error to charge font";
    }
    sf::Text text;
    Texture btnPlay;
    Texture btnMenu;
    if(!btnPlay.loadFromFile("src/images/btn/btnPlay.png")){
        cout<<"Error to charge image";
    }
    if(!btnMenu.loadFromFile("src/images/btn/btnMenu.png")){
        cout<<"Error to charge image";
    }

    RenderWindow window(sf::VideoMode(1200, 800), "GAME SETTINGS");
    text.setFont(font);
    text.setString("NUMBER OF PARTS INTO WICH THE IMAGE IS DIVIDED");
    text.setCharacterSize(30); // in pixels, not points!
    text.setFillColor(sf::Color::White);
    text.setPosition(260,330);

    Sprite btnPSprite;
    btnPSprite.setTexture(btnPlay);

    Sprite btnMSprite;
    btnMSprite.setTexture(btnMenu);

    btnPSprite.setOrigin(-80, -100);
    btnMSprite.setOrigin(-650,-150 );

    PuzzleWindow puzzleWindow;
    mainWindow mainWindow;

    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }else if (btnPSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    puzzleWindow.show();
                }
            } else if (btnMSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    mainWindow.show();
                }
            }
        }
        window.clear(Color(35, 181, 184));
        window.draw(text);
        window.draw(btnPSprite);
        window.draw(btnMSprite);
        window.display();
    }
}

