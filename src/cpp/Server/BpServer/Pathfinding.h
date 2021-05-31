//
// Created by diegoubuntu on 30/5/21.
//

#ifndef PROYECTO_II_PATHFINDING_H
#define PROYECTO_II_PATHFINDING_H

#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 10

typedef pair<int, int> Pair;

typedef pair<double, pair<int, int> > pPair;

class Pathfinding {
    struct cell {
        int parent_i, parent_j;
        double f, g, h;
    };
    bool isValid(int row, int col);

    bool isUnBlocked (int grid[][COL], int row, int col);

    bool isDestination(int row, int col, Pair dest);

    double calculateHValue(int row, int col, Pair dest);

    void tracePath(cell cellDetails[][COL], Pair dest);

    void aStarSearch(int grid[][COL], Pair src, Pair dest);
};

#endif //PROYECTO_II_PATHFINDING_H
