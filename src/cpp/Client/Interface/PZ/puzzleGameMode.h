/**
  * @file puzzleGameMode.h
  * */

#ifndef PROYECTO_II_PUZZLEGAMEMODE_H
#define PROYECTO_II_PUZZLEGAMEMODE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

using namespace sf;
using namespace std;

class puzzleGameMode {
public:

/**
* @brief  Constructor of the class
*/
    puzzleGameMode();

/**
* @brief Method in charge of the graphic interface of the class
*/
    void show();
};


#endif //PROYECTO_II_PUZZLEGAMEMODE_H
