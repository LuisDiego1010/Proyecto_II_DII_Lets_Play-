//
// Created by garroakion on 10/5/21.
//

#ifndef PROYECTO_II_BPWINDOW_H
#define PROYECTO_II_BPWINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>



using namespace sf;
using namespace std;

class BpWindow {
public:
    BpWindow();
    void Show();
    vector<Sprite> players;
    void setPlayers(int n);
    float xpos();
    float ypos();


};


#endif //PROYECTO_II_BPWINDOW_H
