#include <bits/stdc++.h>
#define ROW 9
#define COL 14
using namespace std;
class Backtracking {
public:

    Backtracking();

    struct Point {
        int x, y;
    };

    struct Node {
        Point pt;
        int dist;
    };



    bool isValid(int row, int col);

    void pathMoves(char mat[][COL], Point src, Point dest);


};
