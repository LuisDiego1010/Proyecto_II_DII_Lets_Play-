//
// Created by diegoubuntu on 28/5/21.
//

#ifndef PROYECTO_II_PATHFINDING_H
#define PROYECTO_II_PATHFINDING_H
#include <bits/stdc++.h>
#define ROW 9
#define COL 14
using namespace std;

typedef pair <int, int> Pair;
typedef pair <double, double> pPair;

class Pathfinding {
public:
    Pathfinding();
    struct cell{
        int parent_i, parent_j;
        double f,g,h;
    };

/**
* @brief Checks that if the adjacent cells are valid for the movement
*/
bool isValid(int row, int col);

/**
* @brief Checks whether the given cell is blocked or not
*/
bool UnBlocked(int grid[][COL], int row, int col);

/**
* @brief Checks whether destination cell has been reached or not
*/

bool isDestination(int row, int col, Pair dest);
};

/**
* @brief Calculate H value
*/
double calculateHValue(int row, int col , Pair dest);

/**
* @brief trace the path from the source to destination
*/
void tracePath(cell cellDetails[][COL], Pair dest);

/**
* @brief Find the shortest path between a given source cell to a destination cell
*/
void void aStarSearch(int grid[][COL], Pair src, Pair dest);

#endif //PROYECTO_II_PATHFINDING_H
