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


    struct Point {
        int x, y;
    };
    BpWindow();
    void Show();
    int gameModePlayers;
    int gameModeGoals;

    void setGameModeGoals(int gameModeGoals);

    void setGameModePlayers(int gameModePlayers);



    vector<Sprite> players;
    Sprite ballBackPath;
    Sprite goalKLeft;
    Sprite goalKRight;

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




};


#endif //PROYECTO_II_BPWINDOW_H
