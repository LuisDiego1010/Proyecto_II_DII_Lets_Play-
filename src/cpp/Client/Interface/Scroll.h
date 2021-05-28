//
// Created by isaac on 27/5/21.
//

#ifndef PROYECTO_II_SCROLL_H
#define PROYECTO_II_SCROLL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

using namespace sf;
using namespace std;

class Scroll: public sf::Drawable{
private:
    virtual void draw(RenderTarget& target, RenderStates states)const;

public:
    /**
     * Create a Scroll and auto determine the square size
     * the size of the InputBox can`t be changed after.
     * @param size
     */
    explicit Scroll(Vector2f size);

public:
    RectangleShape rectangle;
    RectangleShape square;
    RenderWindow* window= nullptr;

    void setWindow(RenderWindow *window);

    int x=0;
    int y=0;
    bool trigger= false;
    int order=0;


    bool isTrigger();

    /**
     * Set the position of the BOX
     * @param x
     * @param y
     */
    void setPosition(int x, int y);
    /**
     * Expected to be in the event mouse mouve
     * determine if the mouse have clicked in the input box
     * @param point
     */
    void scroll();
};


#endif //PROYECTO_II_SCROLL_H
