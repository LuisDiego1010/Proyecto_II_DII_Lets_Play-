//
// Created by garroakion on 10/5/21.
//

#include "bpGameMode.h"
#include "BpWindow.h"
#include "../mainWindow.h"
#include "../InputBox.h"

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

    InputBox n_Obstacles=InputBox(Vector2f(100,20));
    n_Obstacles.setPosition(600, 200);

    InputBox n_Annotations(Vector2f(100,20));
    n_Annotations.setPosition(600, 400);


    BpWindow bpWindow;

    while (window.isOpen()) {
        Event event;
        window.clear();
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }else if (event.type == Event::MouseButtonPressed) {
                if (btnPSprite.getGlobalBounds().contains(translated_pos)) {
                    window.close();
                    bpWindow.Show();
                }else if (btnMSprite.getGlobalBounds().contains(translated_pos)) {
                    window.close();
                    return;
                }else {
                    n_Obstacles.select(translated_pos);
                    n_Annotations.select(translated_pos);
                }
            }else if(event.type==Event::TextEntered){
            n_Obstacles.write(event);
            n_Annotations.write(event);
        }   else if(event.type==Event::TextEntered) {
                n_Obstacles.write(event);
                n_Annotations.write(event);
            }
    }
        window.clear(Color(35, 181, 184));
        window.draw(text);
        window.draw(atext);
        window.draw(n_Obstacles);
        window.draw(n_Annotations);
        window.draw(btnPSprite);
        window.draw(btnMSprite);
        window.display();
    }
}
