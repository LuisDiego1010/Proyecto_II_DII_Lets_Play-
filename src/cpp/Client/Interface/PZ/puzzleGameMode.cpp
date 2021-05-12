//
// Created by garroakion on 10/5/21.
//

#include "puzzleGameMode.h"
#include "PuzzleWindow.h"
#include "../mainWindow.h"
#include "../InputBox.h"

puzzleGameMode::puzzleGameMode() = default;

void puzzleGameMode::show() {
    sf::Font font;
    if (!font.loadFromFile("src/cpp/Client/Interface/Fonts/Ubuntu-Bold.ttf"))
    {
        cout<<"Error to charge font";
    }
    sf::Text text_col;
    sf::Text text_row;
    Texture btnPlay;
    Texture btnMenu;
    if(!btnPlay.loadFromFile("src/images/btn/btnPlay.png")){
        cout<<"Error to charge image";
    }
    if(!btnMenu.loadFromFile("src/images/btn/btnMenu.png")){
        cout<<"Error to charge image";
    }

    RenderWindow window(sf::VideoMode(1200, 800), "GAME SETTINGS");

    text_col.setFont(font);
    text_col.setString("NUMBER OF COLUMNS TO DIVIDE");
    text_col.setCharacterSize(17); // in pixels, not points!
    text_col.setFillColor(sf::Color::White);
    text_col.setPosition(150,10);

    InputBox colum=InputBox(Vector2f(100,10));
    colum.setPosition(50, 10);

    text_row.setFont(font);
    text_row.setString("NUMBER OF ROWS TO DIVIDE");
    text_row.setCharacterSize(17); // in pixels, not points!
    text_row.setFillColor(sf::Color::White);
    text_row.setPosition(150,40);

    InputBox row(Vector2f(100,20));
    row.setPosition(50, 40);

    Sprite btnPSprite;
    btnPSprite.setTexture(btnPlay);

    Sprite btnMSprite;
    btnMSprite.setTexture(btnMenu);

    btnPSprite.setOrigin(-930, -700);
    btnMSprite.setOrigin(-1070,-700 );

    PuzzleWindow puzzleWindow;

    while (window.isOpen()) {
        Event event;
        window.clear();
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates



        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }else if (event.type == Event::MouseButtonPressed){
                if (btnPSprite.getGlobalBounds().contains(translated_pos)){
                    window.close();
                    PuzzleWindow::row=std::stoi(row.text);
                    PuzzleWindow::col=std::stoi(colum.text);
                    puzzleWindow.show();
                }else if (btnMSprite.getGlobalBounds().contains(translated_pos)){
                    window.close();
                    return;
                }else{
                    row.select(translated_pos);
                    colum.select(translated_pos);
                }
            }else if(event.type==Event::TextEntered){
                row.write(event);
                colum.write(event);
            }
        }
        window.clear(Color(35, 181, 184));
        window.draw(text_col);
        window.draw(text_row);
        window.draw(colum);
        window.draw(row);
        window.draw(btnPSprite);
        window.draw(btnMSprite);
        window.display();
    }
}

