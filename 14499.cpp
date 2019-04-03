#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int dx[4] = {0, 0, -1, 1}; // 동 서 북 남
int dy[4] = {1, -1, 0, 0};
int order[1001];
int dice[6] = {0,};
int ndice[6] = {0,};

void movingDice(int order) {
    if(order==0){
        ndice[2]=dice[0];
        ndice[0]=dice[3];
        ndice[3]=dice[5];
        ndice[5]=dice[2];
        ndice[1]=dice[1];
        ndice[4]=dice[4];
    }
    if(order==1){
        ndice[0]=dice[2];
        ndice[2]=dice[5];
        ndice[5]=dice[3];
        ndice[3]=dice[0];
        ndice[1]=dice[1];
        ndice[4]=dice[4];
    }
    if(order==2){
        ndice[0]=dice[4];
        ndice[4]=dice[5];
        ndice[5]=dice[1];
        ndice[1]=dice[0];
        ndice[2]=dice[2];
        ndice[3]=dice[3];
    }
    if(order==3){
        ndice[0]=dice[1];
        ndice[1]=dice[5];
        ndice[5]=dice[4];
        ndice[4]=dice[0];
        ndice[2]=dice[2];
        ndice[3]=dice[3];
    }
}
int main() {
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for (int i = 0; i<k; i++){
        int dir;
        cin >> dir;
        order[i] = dir - 1;
    }

    int sx = x;
    int sy = y;
    for (int i = 0; i<k; i++){
        int nx = sx + dx[order[i]];
        int ny = sy + dy[order[i]];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        movingDice(order[i]);
        // 이동한 칸의 수가 0이면, 주사위의 바닥면에 쓰인 숫자가 복사됨
        if (map[nx][ny] == 0) {
            map[nx][ny] = ndice[5];
        }
        // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사, 칸은 0이 됨.
        else {
            ndice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }
        cout << ndice[0] << endl;
        for(int i=0;i<7;i++)
            dice[i]=ndice[i];
        sx = nx;
        sy = ny;
    }

    return 0;
}

