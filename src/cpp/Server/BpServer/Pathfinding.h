//
// Created by diegoubuntu on 30/5/21.
//

#ifndef PROYECTO_II_PATHFINDING_H
#define PROYECTO_II_PATHFINDING_H

#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 14

typedef pair<int, int> Pair;

typedef pair<double, pair<int, int> > pPair;

/**
* @brief Constructor of the class
*/
class Pathfinding {
    struct cell {
        int parent_i, parent_j;
        double f, g, h;
    };


/**
* @brief Checks that if the adjacent cells are valid for the movement
*/
    bool celdValid(int row, int col);
/**
* @brief Checks whether the given cell is blocked or not
*/
    bool celdUnBlocked (int **grid, int row, int col);
/**
* @brief Checks whether destination cell has been reached or not
*/
    bool goal(int row, int col, Pair dest);
/**
* @brief Calculate H value
*/
    double calculateHValue(int row, int col, Pair dest);
/**
* @brief trace the path from the source to destination
*/
    void showPath(Pair dest);
public:
/**
* @brief Find the shortest path between a given source cell to a destination cell
*/
    void findRoute(int **grid, Pair src, Pair dest);

    cell AnswerPositions[ROW][COL]{};
    vector<int> AnswersX;
    vector<int> AnswersY;

};

#endif //PROYECTO_II_PATHFINDING_H
