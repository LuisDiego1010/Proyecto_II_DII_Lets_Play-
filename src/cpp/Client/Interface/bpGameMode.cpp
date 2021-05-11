//
// Created by garroakion on 10/5/21.
//

#include "bpGameMode.h"

bpGameMode::bpGameMode() {}

void bpGameMode::show() {
    RenderWindow window(sf::VideoMode(200, 200), "GAME SETTINGS");
    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else{

            }
        }
        window.clear(Color(255, 255, 255));
        window.display();
    }


}
