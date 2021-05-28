/**
  * @file Line.h
  * */

#ifndef PROYECTO_II_LINE_H
#define PROYECTO_II_LINE_H


#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

class Line : public sf::Drawable, sf::Transformable {
public:

/**
* @brief Constructor of the class
*/
    Line();
/**
* @brief Constructor of the class
*/
    Line(float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);

/**
* @brief Destructor of the class
*/
    ~Line();

/**
* @brief Getter of the points
*/
    sf::VertexArray getPoints();
/**
* @brief Method in charge of the line update
*/
    void update();
/**
* @brief Method in charge of the render of the class
*/
    void render(sf::RenderTarget &target);

private:
    sf::VertexArray m_points;
    sf::Color m_color;
/**
* @brief Method in charge of draw the line of the shoot
*/
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //PROYECTO_II_LINE_H
