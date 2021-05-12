//
// Created by isaac on 11/5/21.
//

#ifndef PROYECTO_II_INPUTBOX_H
#define PROYECTO_II_INPUTBOX_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class InputBox : public sf::Drawable{
private:
    virtual void draw(RenderTarget& target, RenderStates states)const;

public:

    explicit InputBox(Vector2f size);
    static sf::Font font;
    static bool LFont;

public:
    RectangleShape rectangle;
    string text;
    Text print;
    int x;
    int y;
    bool selected;

    void setPosition(int x, int y);
    void select(Vector2<float> point);
    void write(Event event);
};


#endif //PROYECTO_II_INPUTBOX_H
