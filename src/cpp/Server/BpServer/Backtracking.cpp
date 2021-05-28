
#include "Backtracking.h"

int dRow[] = { -1, 0, 0, 1 };
int dCol[] = { 0, -1, 1, 0 };

bool Backtracking::isValid(int row, int col)
{
    return (row >= 0) && (col >= 0)
           && (row < ROW) && (col < COL);
}



string Backtracking::pathMoves(char mat[][COL],
               Point src, Point dest)
{
    int d[ROW][COL];
    memset(d, -1, sizeof d);


    d[src.x][src.y] = 0;


    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);


    visited[src.x][src.y] = true;


    queue<Node> q;


    Node s = {src, 0};


    q.push(s);


    bool ok = false;


    while (!q.empty()) {


        Node curr = q.front();
        Point pt = curr.pt;

        if (pt.x == dest.x
            && pt.y == dest.y) {

            int xx = pt.x, yy = pt.y;
            int dist = curr.dist;


            d[pt.x][pt.y] = dist;


            string pathmoves = "";


            while (xx != src.x
                   || yy != src.y) {


                if (xx > 0 && d[xx - 1][yy] == dist - 1) {
                    pathmoves += 'D';
                    xx--;
                }


                if (xx < ROW - 1
                    && d[xx + 1][yy]
                       == dist - 1) {
                    pathmoves += 'U';
                    xx++;
                }


                if (yy > 0 && d[xx][yy - 1] == dist - 1) {
                    pathmoves += 'R';
                    yy--;
                }

                if (yy < COL - 1
                    && d[xx][yy + 1]
                       == dist - 1) {
                    pathmoves += 'L';
                    yy++;
                }
                dist--;
            }


            reverse(pathmoves.begin(),
                    pathmoves.end());

            return pathmoves;
        }


        q.pop();


        for (int i = 0; i < 14; i++) {
            int row = pt.x + dRow[i];
            int col = pt.y + dCol[i];


            if (isValid(row, col)
                && (mat[row][col] == '1'
                    || mat[row][col] == 's'
                    || mat[row][col] == 'd')
                && !visited[row][col]) {

                visited[row][col] = true;


                Node adjCell
                        = {{row, col}, curr.dist + 1};
                q.push(adjCell);


                d[row][col] = curr.dist + 1;
            }
        }
    }


    if (!ok)
        cout << -1;
}


Backtracking::Backtracking() {

}

