//
// Created by diegoubuntu on 30/5/21.
//

#include "Pathfinding.h"

/*----------------Verify Celd Valid-----------------*/
bool Pathfinding::celdValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

/*----------------Verify Celd Blocked-----------------*/
bool Pathfinding::celdUnBlocked(int (**grid), int row, int col) {
    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}
/*----------------Verify is Goal-----------------*/
bool Pathfinding::goal(int row, int col, Pair dest) {
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
/*----------------Calculate is HValue-----------------*/
double Pathfinding::calculateHValue(int row, int col, Pair dest) {
    return ((double) sqrt(
            (row - dest.first) * (row - dest.first)
            + (col - dest.second) * (col - dest.second)));
}
/*----------------Show Search Result-----------------*/
void Pathfinding::showPath(Pair dest) {
    cout << "\nThe Path is ";
    int row = dest.first;
    int col = dest.second;

    AnswersX = vector<int>();
    AnswersY = vector<int>();

    while (!(AnswerPositions[row][col].parent_i == row
             && AnswerPositions[row][col].parent_j == col)) {
        AnswersX.push_back(col);
        AnswersY.push_back(row);
        int temp_row = AnswerPositions[row][col].parent_i;
        int temp_col = AnswerPositions[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

//    int pos = 0;
//    while (pos != AnswersY.size()) {
//        printf("-> (%d,%d) ", AnswersX[pos], AnswersY[pos]);
//        pos++;
//    }

}
/*----------------Find Route-----------------*/
void Pathfinding::findRoute(int (**grid), Pair src, Pair dest) {

    if (!celdValid(src.first, src.second)) {
        //Invalid Start
        return;
    }

    if (!celdValid(dest.first, dest.second)) {
        //Invalid Destination
        return;
    }

    if (!celdUnBlocked(grid, src.first, src.second) || !celdUnBlocked(grid, dest.first, dest.second)) {
        //Destination Blocked";
        return;
    }

    if (goal(src.first, src.second, dest)) {
        //Is in the destination
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    int i, j;

    //Matrix for details of cell
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            AnswerPositions[i][j].f = FLT_MAX;
            AnswerPositions[i][j].g = FLT_MAX;
            AnswerPositions[i][j].h = FLT_MAX;
            AnswerPositions[i][j].parent_i = -1;
            AnswerPositions[i][j].parent_j = -1;
        }
    }
    //Initialising the parameters of the starting node
    i = src.first, j = src.second;
    AnswerPositions[i][j].f = 0.0;
    AnswerPositions[i][j].g = 0.0;
    AnswerPositions[i][j].h = 0.0;
    AnswerPositions[i][j].parent_i = i;
    AnswerPositions[i][j].parent_j = j;

    set<pPair> openList;

    openList.insert(make_pair(0.0, make_pair(i, j)));

    bool foundDest = false;

    while (!openList.empty()) {
        pPair p = *openList.begin();

        // Remove this vertex from the open list
        openList.erase(openList.begin());

        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        // To save the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;

        //Firts Successor
        if (celdValid(i - 1, j)) {

            if (goal(i - 1, j, dest)) {
                AnswerPositions[i - 1][j].parent_i = i;
                AnswerPositions[i - 1][j].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j]
                       && celdUnBlocked(grid, i - 1, j)) {
                gNew = AnswerPositions[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i - 1][j].f == FLT_MAX
                    || AnswerPositions[i - 1][j].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i - 1, j)));

                    AnswerPositions[i - 1][j].f = fNew;
                    AnswerPositions[i - 1][j].g = gNew;
                    AnswerPositions[i - 1][j].h = hNew;
                    AnswerPositions[i - 1][j].parent_i = i;
                    AnswerPositions[i - 1][j].parent_j = j;
                }
            }
        }

        //Second Successor
        if (celdValid(i + 1, j)) {

            if (goal(i + 1, j, dest)) {
                AnswerPositions[i + 1][j].parent_i = i;
                AnswerPositions[i + 1][j].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j]
                       && celdUnBlocked(grid, i + 1, j)) {
                gNew = AnswerPositions[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i + 1][j].f == FLT_MAX
                    || AnswerPositions[i + 1][j].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i + 1, j)));

                    AnswerPositions[i + 1][j].f = fNew;
                    AnswerPositions[i + 1][j].g = gNew;
                    AnswerPositions[i + 1][j].h = hNew;
                    AnswerPositions[i + 1][j].parent_i = i;
                    AnswerPositions[i + 1][j].parent_j = j;
                }
            }
        }
        // Successor Third
        if (celdValid(i, j + 1)) {

            if (goal(i, j + 1, dest)) {

                AnswerPositions[i][j + 1].parent_i = i;
                AnswerPositions[i][j + 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i][j + 1]
                       && celdUnBlocked(grid, i, j + 1)) {
                gNew = AnswerPositions[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i][j + 1].f == FLT_MAX
                    || AnswerPositions[i][j + 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i, j + 1)));

                    AnswerPositions[i][j + 1].f = fNew;
                    AnswerPositions[i][j + 1].g = gNew;
                    AnswerPositions[i][j + 1].h = hNew;
                    AnswerPositions[i][j + 1].parent_i = i;
                    AnswerPositions[i][j + 1].parent_j = j;
                }
            }
        }
        // Successor fourth
        if (celdValid(i, j - 1)) {
            if (goal(i, j - 1, dest)) {
                AnswerPositions[i][j - 1].parent_i = i;
                AnswerPositions[i][j - 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i][j - 1]
                       && celdUnBlocked(grid, i, j - 1)) {
                gNew = AnswerPositions[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i][j - 1].f == FLT_MAX
                    || AnswerPositions[i][j - 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i, j - 1)));

                    AnswerPositions[i][j - 1].f = fNew;
                    AnswerPositions[i][j - 1].g = gNew;
                    AnswerPositions[i][j - 1].h = hNew;
                    AnswerPositions[i][j - 1].parent_i = i;
                    AnswerPositions[i][j - 1].parent_j = j;
                }
            }
        }
        // Successor fifth
        if (celdValid(i - 1, j + 1)) {

            if (goal(i - 1, j + 1, dest)) {
                AnswerPositions[i - 1][j + 1].parent_i = i;
                AnswerPositions[i - 1][j + 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j + 1]
                       && celdUnBlocked(grid, i - 1, j + 1)) {
                gNew = AnswerPositions[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j + 1, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i - 1][j + 1].f == FLT_MAX
                    || AnswerPositions[i - 1][j + 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i - 1, j + 1)));


                    AnswerPositions[i - 1][j + 1].f = fNew;
                    AnswerPositions[i - 1][j + 1].g = gNew;
                    AnswerPositions[i - 1][j + 1].h = hNew;
                    AnswerPositions[i - 1][j + 1].parent_i = i;
                    AnswerPositions[i - 1][j + 1].parent_j = j;
                }
            }
        }
        // Successor sixth
        if (celdValid(i - 1, j - 1)) {

            if (goal(i - 1, j - 1, dest)) {
                AnswerPositions[i - 1][j - 1].parent_i = i;
                AnswerPositions[i - 1][j - 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j - 1] && celdUnBlocked(grid, i - 1, j - 1)) {
                gNew = AnswerPositions[i][j].g + 1.414;
                hNew = calculateHValue(i - 1, j - 1, dest);
                fNew = gNew + hNew;


                if (AnswerPositions[i - 1][j - 1].f == FLT_MAX
                    || AnswerPositions[i - 1][j - 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i - 1, j - 1)));
                    AnswerPositions[i - 1][j - 1].f = fNew;
                    AnswerPositions[i - 1][j - 1].g = gNew;
                    AnswerPositions[i - 1][j - 1].h = hNew;
                    AnswerPositions[i - 1][j - 1].parent_i = i;
                    AnswerPositions[i - 1][j - 1].parent_j = j;
                }
            }
        }
        // Successor seventh
        if (celdValid(i + 1, j + 1)) {

            if (goal(i + 1, j + 1, dest)) {

                AnswerPositions[i + 1][j + 1].parent_i = i;
                AnswerPositions[i + 1][j + 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j + 1] && celdUnBlocked(grid, i + 1, j + 1)) {
                gNew = AnswerPositions[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j + 1, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i + 1][j + 1].f == FLT_MAX
                    || AnswerPositions[i + 1][j + 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i + 1, j + 1)));

                    AnswerPositions[i + 1][j + 1].f = fNew;
                    AnswerPositions[i + 1][j + 1].g = gNew;
                    AnswerPositions[i + 1][j + 1].h = hNew;
                    AnswerPositions[i + 1][j + 1].parent_i = i;
                    AnswerPositions[i + 1][j + 1].parent_j = j;
                }
            }
        }
        //Succesor eighth
        if (celdValid(i + 1, j - 1)) {

            if (goal(i + 1, j - 1, dest)) {
                AnswerPositions[i + 1][j - 1].parent_i = i;
                AnswerPositions[i + 1][j - 1].parent_j = j;
                cout << "founded\n";
                showPath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j - 1] && celdUnBlocked(grid, i + 1, j - 1)) {
                gNew = AnswerPositions[i][j].g + 1.414;
                hNew = calculateHValue(i + 1, j - 1, dest);
                fNew = gNew + hNew;

                if (AnswerPositions[i + 1][j - 1].f == FLT_MAX
                    || AnswerPositions[i + 1][j - 1].f > fNew) {
                    openList.insert(make_pair(
                            fNew, make_pair(i + 1, j - 1)));

                    AnswerPositions[i + 1][j - 1].f = fNew;
                    AnswerPositions[i + 1][j - 1].g = gNew;
                    AnswerPositions[i + 1][j - 1].h = hNew;
                    AnswerPositions[i + 1][j - 1].parent_i = i;
                    AnswerPositions[i + 1][j - 1].parent_j = j;
                }
            }
        }
    }

    if (!foundDest)
        cout << "Failed to find the Destination Cell\n";
}