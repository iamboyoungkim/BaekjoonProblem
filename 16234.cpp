#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <math.h>

using namespace std;

int N, L, R;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int arr[51][51];
bool go = true;
int res = -1;

queue<pair<int, int>> unionMem;
queue<pair<int, int>> q;

int main() {
    cin >> N >> L >> R;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    while (go) {
        bool isVisit[51][51] = {false, };
        go = false;
        res += 1;

        for (int i = 0; i<N; i++){
            for (int j = 0; j<N; j++){
                if (isVisit[i][j] == true) continue;
                int sum = arr[i][j];
                unionMem.push(make_pair(i,j));
                q.push(make_pair(i,j));
                isVisit[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nextX = x + dx[k];
                        int nextY = y + dy[k];
                        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N
                            && isVisit[nextX][nextY] == false
                            && abs(arr[x][y] - arr[nextX][nextY]) >= L && abs(arr[x][y] - arr[nextX][nextY]) <= R) {
                            go = true;
                            isVisit[nextX][nextY] = true;
                            q.push(make_pair(nextX, nextY));
                            unionMem.push(make_pair(nextX, nextY));
                            sum += arr[nextX][nextY];
                        }
                    }
                }
                int average = sum / unionMem.size();
                while(!unionMem.empty()) {
                    arr[unionMem.front().first][unionMem.front().second] = average;
                    unionMem.pop();
                }
            }
        }
    }
    cout << res;

    return 0;
}