//
// Created by garroakion on 10/5/21.
//

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
    PuzzleWindow();
    void show();

};


#endif //PROYECTO_II_PUZZLEWINDOW_H