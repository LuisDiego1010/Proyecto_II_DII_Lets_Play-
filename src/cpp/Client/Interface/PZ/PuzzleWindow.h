/**
  * @file PuzzleWindow.h
  * */

#ifndef PROYECTO_II_PUZZLEWINDOW_H
#define PROYECTO_II_PUZZLEWINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

using namespace sf;
using namespace std;

class PuzzleWindow {
public:
    static int col;
    static int row;
    static float length_x;
    static float length_y;

/**
* @brief Constructor of the class
*/
    PuzzleWindow();

/**
* @brief In charge of the graphic interface of the class
*/
    void show();

/**
 * Recieve a Matrix as Array as vector and reposition with the order of the id the sprtes in the window.
 * @param subimages
 * @param order
 */
    void order(Sprite *subimages, std::vector<int> order);
};


#endif //PROYECTO_II_PUZZLEWINDOW_H
