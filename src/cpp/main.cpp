#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


using namespace sf;
using namespace std;
int main()
{
    RenderWindow window(sf::VideoMode(1000, 1000), "Let's Play");
    Texture BpGame;
    Texture PuzzleGame;
    if(!BpGame.loadFromFile("/home/garroakion/Desktop/TEC/src/cpp/bg.png")){
        cout<<"No se puede cargar la imagen";
    }
    if(!PuzzleGame.loadFromFile("/home/garroakion/Desktop/TEC/src/cpp/bg.png")){
        cout<<"No se puede cargar la imagen";
    }

    Sprite bpSprite;
    bpSprite.setTexture(BpGame);

    Sprite puzzleSprite;
    puzzleSprite.setTexture(PuzzleGame);

    bpSprite.setOrigin(-80,-100 );
    //Vector2u size = texture.getSize();
    puzzleSprite.setOrigin(-80,-500 );


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear(Color(255, 255, 255));
        //window.clear(Color(35, 181, 184));
        window.draw(bpSprite);
        window.draw(puzzleSprite);
        window.display();
    }

    return 0;
}