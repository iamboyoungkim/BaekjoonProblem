#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

char maze[51][51];
int visit[51][51][64];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
int posX, posY;
int newPos;

int bfs() {
    visit[posX][posY][0] = 1;
    queue<pair<pair<int, int>, int>> q; // 현재 위치, bitmask 값
    q.push({{posX, posY}, 0});
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int bit = q.front().second;
        q.pop();
        
        if (maze[x][y] == '1') // 출구
            return visit[x][y][bit] - 1;
        
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            int original = visit[x][y][bit];
            
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || maze[nextX][nextY] == '#' || visit[nextX][nextY][bit] != 0) 
            // 범위 초과 or 벽 or 방문했을 때
                continue;
            if (maze[nextX][nextY] >= 'a' && maze[nextX][nextY] <= 'z') { // 언제나 이동 가능. 열쇠를 집음 -> 새로 추가
                newPos = bit | (1 << (maze[nextX][nextY]) - 'a');
                if (visit[nextX][nextY][newPos] == 0) { // 아직 방문하지 않았을 경우
                    visit[nextX][nextY][bit] = original + 1;
                    visit[nextX][nextY][newPos] = original + 1;
                    q.push({{nextX, nextY}, newPos});
                }
            }
            if (maze[nextX][nextY] >= 'A' && maze[nextX][nextY] <= 'Z') { // 대응하는 열쇠가 있을 때만 이동할 수 있음
                newPos = bit & (1 << (maze[nextX][nextY]) - 'A');
                if (newPos != 0) {
                    visit[nextX][nextY][bit] = original + 1;
                    q.push({{nextX, nextY}, bit});
                }
            }
            else if (visit[nextX][nextY][bit] == 0) { // 아직 방문하지 않았을 경우
                visit[nextX][nextY][bit] = original + 1;
                q.push({{nextX, nextY}, bit});
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '0') {
                posX = i;
                posY = j;
            }
        }
    }
    cout << bfs() << '\n';
    return 0;
}
