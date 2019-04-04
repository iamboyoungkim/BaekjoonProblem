#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

// 회전
int dx[4] = { -1, 0, 1, 0};// 북 동 남 서
int dy[4] = { 0, 1, 0, -1};

// 후진
int back_dx[4] = { 1, 0, -1, 0};// 남 서 북 동
int back_dy[4] = { 0, -1, 0, 1};

int n, m, r, c, d;
int res;
int map[51][51];

void dfs(int x, int y, int direction) {
    if (map[x][y] == 1)
        return;
    if (map[x][y] == 0){
        res++;
        map[x][y] = 2;
    }
    for (int i = 0; i<4; i++){
        // 북 (0) -> 서 (3)
        // 서 (3) -> 남 (2)
        // 동 (1) -> 북 (0)
        // 남(2) -> 동 (1)
        int nd;
        if (direction == 1 || direction == 2 || direction == 3) nd = direction-1;
        else if (direction == 0) nd = 3;

        int nx = x + dx[nd];
        int ny = y + dy[nd];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (map[nx][ny] == 0){
                dfs(nx, ny, nd);
                return;
            }
            else direction = nd;
        }
    }
    // 모두 청소됨
    int nx = x + back_dx[direction];
    int ny = y + back_dy[direction];
    dfs(nx, ny, direction);
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    dfs(r,c,d);
    cout << res;

    return 0;
}

