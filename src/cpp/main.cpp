#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

using namespace sf;
using namespace std;
int main()
{
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

    bpSprite.setOrigin(-80,-100 );
    //Vector2u size = texture.getSize();
    puzzleSprite.setOrigin(-650,-100 );


    while (window.isOpen())
    {
        Event event;
        auto mouse_pos = sf::Mouse::getPosition(window); // Mouse position relative to the window
        auto translated_pos = window.mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
            }


            else if(bpSprite.getGlobalBounds().contains(translated_pos)){
                if (event.type == Event::MouseButtonPressed){

                }
            }
            else if(puzzleSprite.getGlobalBounds().contains(translated_pos)){
                if (event.type == Event::MouseButtonPressed){

                }
            }


        }
        window.clear(Color(255, 255, 255));
        //window.clear(Color(35, 181, 184));
        window.draw(bpSprite);
        window.draw(puzzleSprite);
        window.display();

    }

    return 0;
}