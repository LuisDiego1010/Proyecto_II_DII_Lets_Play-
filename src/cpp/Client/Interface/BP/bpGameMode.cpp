//
// Created by garroakion on 10/5/21.
//

#include "bpGameMode.h"
#include "BpWindow.h"
#include "../mainWindow.h"

bpGameMode::bpGameMode() {}

void bpGameMode::show() {
    Texture btnPlay;
    Texture btnMenu;
    if(!btnPlay.loadFromFile("src/images/btn/btnPlay.png")){
        cout<<"Error to charge image";
    }
    if(!btnMenu.loadFromFile("src/images/btn/btnMenu.png")){
        cout<<"Error to charge image";
    }
    sf::Font font;
    if (!font.loadFromFile("src/cpp/Client/Interface/Fonts/Ubuntu-Bold.ttf"))
    {
    cout<<"Error to charge font";
    }
    RenderWindow window(sf::VideoMode(1200, 800), "GAME SETTINGS");
    sf::Text text;

    text.setFont(font);
    text.setString("NUMBER OF OBSTACLES");
    text.setCharacterSize(30); // in pixels, not points!
    text.setFillColor(sf::Color::White);
    text.setPosition(450,110);
    sf::Text atext;
    atext.setFont(font);
    atext.setString("NUMBER OF ANNOTATIONS");
    atext.setCharacterSize(30); // in pixels, not points!
    atext.setFillColor(sf::Color::White);
    atext.setPosition(430,310);

    Sprite btnPSprite;
    btnPSprite.setTexture(btnPlay);

    Sprite btnMSprite;
    btnMSprite.setTexture(btnMenu);

    btnPSprite.setOrigin(-930, -700);
    btnMSprite.setOrigin(-1070,-700 );

    BpWindow bpWindow;

    while (window.isOpen()) {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }else if (btnPSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    window.close();
                    bpWindow.Show();
                }
            } else if (btnMSprite.getGlobalBounds().contains(translated_pos)) {
                if (event.type == Event::MouseButtonPressed) {
                    window.close();
                    return;
                }
            }
            else{
            }
        }
        window.clear(Color(35, 181, 184));
        window.draw(text);
        window.draw(atext);
        window.draw(btnPSprite);
        window.draw(btnMSprite);
        window.display();

    }
}
