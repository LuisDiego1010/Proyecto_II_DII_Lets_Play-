//
// Created by diegoubuntu on 30/5/21.
//

#include "Pathfinding.h"

bool Pathfinding::isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool Pathfinding::isUnBlocked(int (*grid)[14], int row, int col) {
    if (grid[row][col] == 1)
        return (true);
    else
        return (false);
}

bool Pathfinding::isDestination(int row, int col, Pair dest) {
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}

double Pathfinding::calculateHValue(int row, int col, Pair dest) {
    return ((double) sqrt(
            (row - dest.first) * (row - dest.first)
            + (col - dest.second) * (col - dest.second)));
}

void Pathfinding::tracePath(Pair dest) {
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

void Pathfinding::aStarSearch(int (*grid)[14], Pair src, Pair dest) {

    if (!isValid(src.first, src.second)) {
        cout << "Source is invalid\n";
        return;
    }

    if (!isValid(dest.first, dest.second)) {
        cout << "Destination is invalid\n";
        return;
    }

    if (!isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second)) {
        cout << "Source or the destination is blocked\n";
        return;
    }

    if (isDestination(src.first, src.second, dest)) {
        cout << "We are already at the destination\n";
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            AnswerPositions[i][j].f = FLT_MAX;
            AnswerPositions[i][j].g = FLT_MAX;
            AnswerPositions[i][j].h = FLT_MAX;
            AnswerPositions[i][j].parent_i = -1;
            AnswerPositions[i][j].parent_j = -1;
        }
    }

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

        openList.erase(openList.begin());

        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        double gNew, hNew, fNew;

        if (isValid(i - 1, j)) {

            if (isDestination(i - 1, j, dest)) {
                AnswerPositions[i - 1][j].parent_i = i;
                AnswerPositions[i - 1][j].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j]
                       && isUnBlocked(grid, i - 1, j)) {
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

        if (isValid(i + 1, j)) {

            if (isDestination(i + 1, j, dest)) {
                AnswerPositions[i + 1][j].parent_i = i;
                AnswerPositions[i + 1][j].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j]
                       && isUnBlocked(grid, i + 1, j)) {
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

        if (isValid(i, j + 1)) {

            if (isDestination(i, j + 1, dest)) {

                AnswerPositions[i][j + 1].parent_i = i;
                AnswerPositions[i][j + 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i][j + 1]
                       && isUnBlocked(grid, i, j + 1)) {
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

        if (isValid(i, j - 1)) {
            if (isDestination(i, j - 1, dest)) {
                AnswerPositions[i][j - 1].parent_i = i;
                AnswerPositions[i][j - 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i][j - 1]
                       && isUnBlocked(grid, i, j - 1)) {
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

        if (isValid(i - 1, j + 1)) {

            if (isDestination(i - 1, j + 1, dest)) {
                AnswerPositions[i - 1][j + 1].parent_i = i;
                AnswerPositions[i - 1][j + 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j + 1]
                       && isUnBlocked(grid, i - 1, j + 1)) {
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

        if (isValid(i - 1, j - 1)) {

            if (isDestination(i - 1, j - 1, dest)) {
                AnswerPositions[i - 1][j - 1].parent_i = i;
                AnswerPositions[i - 1][j - 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i - 1][j - 1] && isUnBlocked(grid, i - 1, j - 1)) {
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

        if (isValid(i + 1, j + 1)) {

            if (isDestination(i + 1, j + 1, dest)) {

                AnswerPositions[i + 1][j + 1].parent_i = i;
                AnswerPositions[i + 1][j + 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j + 1] && isUnBlocked(grid, i + 1, j + 1)) {
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

        if (isValid(i + 1, j - 1)) {

            if (isDestination(i + 1, j - 1, dest)) {
                AnswerPositions[i + 1][j - 1].parent_i = i;
                AnswerPositions[i + 1][j - 1].parent_j = j;
                cout << "founded\n";
                tracePath(dest);
                foundDest = true;
                return;
            } else if (!closedList[i + 1][j - 1] && isUnBlocked(grid, i + 1, j - 1)) {
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