/**
  * @file bpGameMode.h
  * */

#ifndef PROYECTO_II_BPGAMEMODE_H
#define PROYECTO_II_BPGAMEMODE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

using namespace sf;
using namespace std;

class bpGameMode {
public:
/**
 * @brief Constructor de la clase
 *
 */
    bpGameMode();

 /**
 * @brief Responsible for displaying the configuration window.
 */
    void show();

};


#endif //PROYECTO_II_BPGAMEMODE_H
