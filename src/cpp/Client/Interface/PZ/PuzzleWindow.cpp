//
// Created by garroakion on 10/5/21.
//

#include "PuzzleWindow.h"

PuzzleWindow::PuzzleWindow() {}

void PuzzleWindow::show() {
    RenderWindow window(sf::VideoMode(1200, 1400), "GENETIC PUZZLE");
    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.clear(Color(255, 255, 255));
        window.display();
    }
}
