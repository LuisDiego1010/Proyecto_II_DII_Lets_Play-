//
// Created by isaac on 27/5/21.
//

#include "Scroll.h"
#include <iostream>
#include <cmath>
using namespace sf;
using namespace std;


void Scroll::draw(RenderTarget &target, RenderStates states) const {
    target.draw(rectangle);
    target.draw(square);
}

Scroll::Scroll(Vector2f size) {
    rectangle=RectangleShape(size);
    square=RectangleShape(Vector2f(size.x/25, size.y-2));
    square.setFillColor(sf::Color::Cyan);
}

void Scroll::setPosition(int xPos, int yPos) {
    rectangle.setPosition(xPos,yPos);
    square.setPosition(xPos,yPos+1);
    this->x=xPos;
    this->y=yPos;
}

void Scroll::scroll() {
    auto mouse_pos = sf::Mouse::getPosition(*window); // Mouse position relative to the window
    auto translated_pos = window->mapPixelToCoords(mouse_pos); // Mouse position translated into world coordinates

    if(rectangle.getGlobalBounds().contains(translated_pos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            square.setPosition(translated_pos.x,y);
            int tmporder=(int)round((square.getPosition().x-this->x)/square.getSize().x);
            if(tmporder!=order && tmporder<25){
                order=tmporder;
                trigger=true;
                std::cout<<" "<<order;
            }
        }
    }else{
        return;
    }
}

bool Scroll::isTrigger() {
    if(trigger){
        trigger=false;
        return true;
    }
    return trigger;
}

void Scroll::setWindow(RenderWindow *window) {
    this->window = window;
}
