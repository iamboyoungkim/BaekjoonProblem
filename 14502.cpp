#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> zeroInfo;
int map[9][9];
int copyMap[9][9];

int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};

// 바이러스 전파
void dfs(int x, int y){
    for (int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m){
            if (copyMap[nx][ny] == 0) {
                copyMap[nx][ny] = 2;
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> map[i][j];
            if (map[i][j] == 0)
                zeroInfo.push_back(make_pair(i, j));
        }
    }
    int max = -1;
    for (int i = 0; i<zeroInfo.size(); i++){
        for (int j = 0; j<zeroInfo.size(); j++){
            for (int k = 0; k<zeroInfo.size(); k++){
                if (i == j || i == k || j == k ) continue;
                int x = zeroInfo[i].first;
                int y = zeroInfo[i].second;
                int x2 = zeroInfo[j].first;
                int y2 = zeroInfo[j].second;
                int x3 = zeroInfo[k].first;
                int y3 = zeroInfo[k].second;

                for (int a = 0; a<n; a++){
                    for (int b = 0; b<m; b++){
                        copyMap[a][b] = map[a][b];
                    }
                }
                copyMap[x][y] = 1;
                copyMap[x2][y2] = 1;
                copyMap[x3][y3] = 1;

                // dfs로 감염시키기
                for (int a = 0; a<n; a++){
                    for (int b = 0; b<m; b++){
                        if (copyMap[a][b] == 2 ){
                            dfs(a,b);
                        }
                    }
                }
                // 안전 영역 갯수 출력
                int cnt = 0;
                for (int a = 0; a<n; a++){
                    for (int b = 0; b<m; b++){
                        if (copyMap[a][b] == 0) cnt += 1;
                    }
                }
                if (max < cnt) max = cnt;
            }
        }
    }
    cout << max;
    return 0;
}
