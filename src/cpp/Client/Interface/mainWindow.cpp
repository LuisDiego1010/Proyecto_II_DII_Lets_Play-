//
// Created by garroakion on 10/5/21.
//

#include "mainWindow.h"
#include "BP/bpGameMode.h"
#include "PZ/puzzleGameMode.h"
#include "nlohmann/json.hpp"
#include "../Socket_Client.h"


mainWindow::mainWindow() = default;

void mainWindow::show() {
    Socket_Client * socket = Socket_Client::self;

    RenderWindow window(sf::VideoMode(1200, 750), "Let's Play");
    Texture BpGame;
    Texture PuzzleGame;
    if(!BpGame.loadFromFile("src/images/BPGAME.png")){
        cout<<"No se puede cargar la imagen";
    }
    if(!PuzzleGame.loadFromFile("src/images/Genetic Puzzle.png")){
        cout<<"No se puede cargar la imagen";
    }

    Sprite bpSprite;
    bpSprite.setTexture(BpGame);

    Sprite puzzleSprite;
    puzzleSprite.setTexture(PuzzleGame);

    bpSprite.setOrigin(-80, -100);
    puzzleSprite.setOrigin(-650,-150 );

    bpGameMode bpGameMode;
    puzzleGameMode puzzleGameMode;

    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (bpSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    nlohmann::json game;
                    game["Game"]="BP";
                    std::cout<<socket->comunicatte(to_string(game));
                    bpGameMode.show();
                    window.requestFocus();
                }
            } else if (puzzleSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    nlohmann::json game;
                    game["Game"]="Genetic";
                    std::cout<<socket->comunicatte(to_string(game));
                    puzzleGameMode.show();
                    window.requestFocus();
                }
            }
        }
        window.clear(Color(55, 177, 188));
        window.draw(bpSprite);
        window.draw(puzzleSprite);
        window.display();
    }
}
