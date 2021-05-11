//
// Created by garroakion on 10/5/21.
//

#include "mainWindow.h"
#include "bpGameMode.h"
#include "puzzleGameMode.h"



mainWindow::mainWindow() {

}

void mainWindow::show() {

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
                    bpGameMode.show();
                }
            } else if (puzzleSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    puzzleGameMode.show();
                }
            }
        }
        window.clear(Color(55, 177, 188));
        window.draw(bpSprite);
        window.draw(puzzleSprite);
        window.display();
    }
}
