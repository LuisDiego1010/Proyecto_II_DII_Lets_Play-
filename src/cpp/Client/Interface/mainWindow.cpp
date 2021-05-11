//
// Created by garroakion on 10/5/21.
//

#include "mainWindow.h"
#include "BpWindow.h"
#include "PuzzleWindow.h"


mainWindow::mainWindow() {

}

void mainWindow::show() {

    RenderWindow window(sf::VideoMode(1200, 1400), "Let's Play");
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
    //Vector2u size = texture.getSize();
    puzzleSprite.setOrigin(-650,-100 );

    BpWindow bpWindow;
    PuzzleWindow puzzleWindow;
    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (bpSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    bpWindow.Show();
                }
            } else if (puzzleSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    puzzleWindow.show();
                }
            }
        }
        window.clear(Color(255, 255, 255));
        //window.clear(Color(35, 181, 184));
        window.draw(bpSprite);
        window.draw(puzzleSprite);
        window.display();
    }
}
