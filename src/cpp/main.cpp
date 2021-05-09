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
    Texture texture;
    texture.loadFromFile("bg.png");
    Sprite sprite;
    Vector2u size = texture.getSize();
    sprite.setTexture(texture);
    sprite.setOrigin(size.x / 2, size.y / 2);


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
        window.draw(sprite);
        window.display();
    }

    return 0;
}