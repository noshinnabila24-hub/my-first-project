#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n = 4;
    int blocked[3][2] = {{2,2}, {1,3}, {2,1}};
    int blocked_count = 3;

    int canGo[4][4];
    int visited[4][4];

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            canGo[i][j] = 1;
            visited[i][j] = 0;
        }
    }

    for(int i=0; i<blocked_count; i++) {
        int x = blocked[i][0];
        int y = blocked[i][1];
        canGo[x][y] = 0;
    }


    queue<int> qx, qy;

    qx.push(0);
    qy.push(0);
    visited[0][0] = 1;

    int found = 0;

    while(!qx.empty() && found == 0) {
        int x = qx.front();
        int y = qy.front();
        qx.pop();
        qy.pop();


        if(x == 3 && y == 3) {
            found = 1;
            break;
        }

        if(x+1 < 4 && canGo[x+1][y] == 1 && visited[x+1][y] == 0) {
            qx.push(x+1);
            qy.push(y);
            visited[x+1][y] = 1;
        }

        if(x-1 >= 0 && canGo[x-1][y] == 1 && visited[x-1][y] == 0) {
            qx.push(x-1);
            qy.push(y);
            visited[x-1][y] = 1;
        }

        if(y+1 < 4 && canGo[x][y+1] == 1 && visited[x][y+1] == 0) {
            qx.push(x);
            qy.push(y+1);
            visited[x][y+1] = 1;
        }

        if(y-1 >= 0 && canGo[x][y-1] == 1 && visited[x][y-1] == 0) {
            qx.push(x);
            qy.push(y-1);
            visited[x][y-1] = 1;
        }
    }

    if(found == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
