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
#include "Collision.h"
#include <queue>


using namespace sf;
using namespace std;

class BpWindow {
public:


    struct Point {
        int x, y;
    };



    /**
   * @brief Constructor of the class
   */
    BpWindow();

    /**
    * @brief In charge of the initial configuration of the BpGame elements
    */
    void Show();

    RenderWindow *window;
    int gameModePlayers;
    int gameModeGoals;
    int n_goaLPlayer1;
    int n_goaLPlayer2;
    sf::Text scorePlayer1;
    sf::Text scorePlayer2;
    sf::Text allGoals;
    string strscorePlayer1;
    string strscorePlayer2;
    string strallscore;
    bool goalLeft;
    bool goalRight;
    bool turnPlayer=false;
    vector<Sprite> players;
    vector<Sprite> drawRouteSprites;
    vector<Sprite> pathSprites;
    Sprite ballBackPath;
    Sprite goalKLeft;
    Sprite goalKRight;
    char backtracking[9][14]{};
    string route;
    bool moving;
    bool path;
    Texture squarepath;

    vector<int> pathX;
    vector<int> pathY;

    Vector2f velocity;
    Vector2f position;
    float dt;
    Clock dt_clock;
    sf::Font font;


    /**
    * @brief Setter of match goals
    */
    int setGameModeGoals(int gameModeGoals);

/**
* @brief Setter of players obstacles
*/
    void setGameModePlayers(int gameModePlayers);

/**
* @brief Method for set the obstacles
*/
    void setPlayers(int n);

/**
* @brief Getter the X position of the ball
*/
    int getPositionXBall();

/**
* @brief Getter the Y position of the ball
*/
    int getPositionYBall();

/**
* @brief Getter the X position of the goal player
*/
    int getPositionXGoalPlayer();

/**
* @brief Getter the Y position of the goal player
*/
    int getPositionYGoalPlayer();

/**
* @brief Getter the X position of the goal Cpu
*/
    int getPositionXGoalCpu();

/**
* @brief Getter the Y position of the goal Cpu
*/
    int getPositionYGoalCpu();

/**
* @brief Method for display binary
*/
    void displayBacktracking();

/**
* @brief Method for set a binary matrix to use in the backtracking
*/
    void setBacktracking();

/**
* @brief Method in charge of the move of the ball
*/
    void ballmove();

/**
* @brief Method for update the line of the shoot
*/
    void updateDirectionLine();

/**
* @brief Method in charge of the colision checks with obstacles
*/
    bool checkCollisionPoint(const Vector2f &mouse);

/**ww
* @brief Method in charge of the colision checks with the limits
*/
    void collisionsBoards();

/**
* @brief Method in charge of the colision checks with the Obstacles 1
*/
    void collsionObstacles1(Sprite player);

/**
* @brief Method in charge of the colision checks with the Obstacles 2
*/
    void collsionObstacles2(Sprite player);

/**
* @brief Method in charge of the colision checks with the Goals
*/
    bool collisionGoal();

/**
* @brief Method create a game over Window
*/
    void GameOver(string Player);

    void drawRoute();

    void drawPath();
    // void showDrawRoute();
    void scoreboard(int n_goalPLayer1, int n_goalPLayer2);

};


#endif //PROYECTO_II_BPWINDOW_H
