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
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Line.h"
#include "Collision.h"




using namespace sf;
using namespace std;

class BpWindow {
public:


    struct Point {
        int x, y;
    };
    BpWindow();
    void Show();
    int gameModePlayers;
    int gameModeGoals;
    int n_goalLeft;
    int n_goalR;
    bool goalLeft;
    bool goalRight;
    Line* direction= nullptr;
    bool dragged;
    Vector2f velocity;
    float dt;
    Clock dt_clock;
    Vector2f m_center;
    float m_radius;

    void setGameModeGoals(int gameModeGoals);

    void setGameModePlayers(int gameModePlayers);



    vector<Sprite> players;
    Sprite ballBackPath;
    Sprite goalKLeft;
    Sprite goalKRight;
    sf::Vector2f m_mouse;

    char backtracking[9][14];

    void setPlayers(int n);

    int getPositionXBall();
    int getPositionYBall();

    int getPositionXGoalPlayer();
    int getPositionYGoalPlayer();

    int getPositionXGoalCpu();
    int getPositionYGoalCpu();

    void displayBacktracking();
    void setBacktracking();

    void ballmove();
    void updateDirectionLine();

    bool checkCollisionPoint(const Vector2f &mouse);

    void collisionsBoards();

    void collsionGoal();

    void collsionObstacles1(Sprite player);

    void collsionObstacles2(Sprite player);
};


#endif //PROYECTO_II_BPWINDOW_H
