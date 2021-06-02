
#include "Backtracking.h"



bool Backtracking::isValid(int row, int col)
{
    return (row >= 0) && (col >= 0)
           && (row < ROW) && (col < COL);
}

//Guarda los movimientos de las direcciones de las celdas adyacentes.
int dRow[] = {-1, 0, 0, 1};
int dCol[] = {0, -1, 1, 0};

string Backtracking::backtrackingRoute(char mat[][COL],
               Point src, Point dest)
{


    int distance[ROW][COL];
    memset(distance, -1, sizeof distance);
    distance[src.x][src.y] = 0;


    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
    visited[src.x][src.y] = true;


    queue<Node> queueDistances;
    Node sourceNode = {src, 0};
    queueDistances.push(sourceNode);


    bool found = false;


    while (!queueDistances.empty()) {


        Node currentNode = queueDistances.front();
        Point position = currentNode.pt;

        if (position.x == dest.x&& position.y == dest.y) {

            int destPosX = position.x;
            int destPosY = position.y;
            int dist = currentNode.dist;


            distance[position.x][position.y] = dist;


            string backtrackingRoute = "";


            while (destPosX != src.x || destPosY != src.y) {


                if (destPosX > 0 && distance[destPosX - 1][destPosY] == dist - 1) {
                    backtrackingRoute += 'D';
                    destPosX--;
                }


                if (destPosX < ROW - 1 && distance[destPosX + 1][destPosY] == dist - 1) {
                    backtrackingRoute += 'U';
                    destPosX++;
                }


                if (destPosY > 0 && distance[destPosX][destPosY - 1] == dist - 1) {
                    backtrackingRoute += 'R';
                    destPosY--;
                }

                if (destPosY < COL - 1 && distance[destPosX][destPosY + 1] == dist - 1) {
                    backtrackingRoute += 'L';
                    destPosY++;
                }
                dist--;
            }
            reverse(backtrackingRoute.begin(),backtrackingRoute.end());
            return backtrackingRoute;
        }


        queueDistances.pop();


        for (int i = 0; i < 14; i++) {
            int row = position.x + dRow[i];
            int col = position.y + dCol[i];

            if (isValid(row, col) && (mat[row][col] == '1'|| mat[row][col] == 's'|| mat[row][col] == 'd') && !visited[row][col]) {

                visited[row][col] = true;
                Node adjCell = {{row, col}, currentNode.dist + 1};
                queueDistances.push(adjCell);
                distance[row][col] = currentNode.dist + 1;
            }
        }
    }


    if (!found)
        cout << -1;
}


Backtracking::Backtracking() {

}

