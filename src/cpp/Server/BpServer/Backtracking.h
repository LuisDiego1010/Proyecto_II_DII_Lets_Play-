/**
  * @file Backtracking.h
  * */





#include <bits/stdc++.h>
#define ROW 9
#define COL 14
using namespace std;
class Backtracking {
public:
/**
* @brief Constructor of the class
*/
    Backtracking();

    struct Point {
        int x, y;
    };

    struct Node {
        Point pt;
        int dist;
    };


/**
* @brief Checks that if the adjacent cells are valid for the movement
*/
    bool isValid(int row, int col);

/**
* @brief Method in charge of backtracking
*/
    string backtrackingRoute(char mat[][COL], Point src, Point dest);


};
