#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[501][501];
int arr[501][501];
int n,m;

int res = -1;


void otherCheck() {
    // ㅗ
    for(int i = 1; i < n; i ++) {
        for(int j = 1; j < m - 1; j ++) {
            int tmp = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1];
            if (res < tmp) res = tmp;;
        }
    }

    // ㅜ
    for(int i = 0; i < n - 1; i ++) {
        for(int j = 1; j < m - 1; j ++) {
            int tmp = arr[i][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1];
            if (res < tmp) res = tmp;;
        }
    }

    // ㅓ
    for(int i = 1; i < n - 1; i ++) {
        for(int j = 1; j < m; j ++) {
            int tmp = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j - 1];
            if (res < tmp) res = tmp;;
        }
    }

    // ㅏ
    for(int i = 1; i < n - 1; i ++) {
        for(int j = 0; j < m - 1; j ++) {
            int tmp = arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1];
            if (res < tmp) res = tmp;;
        }
    }
}

void dfs(int posX, int posY, int idx, int sum){
    if (idx == 4){
        if (res < sum) res = sum;
        return;
    }
    check[posX][posY] = true;
    for (int i = 0; i<4; i++){
        int nextX = posX + dx[i];
        int nextY = posY + dy[i];
        if (nextX >= 0 && nextX < n && nextY >=0 && nextY < m && check[nextX][nextY] == false){
            check[posX][posY] = true;
            dfs(nextX, nextY, idx+1, sum+arr[nextX][nextY]);
            check[posX][posY] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            check[i][j] = true;
            dfs(i,j,1,arr[i][j]);
            check[i][j] = false;
        }
    }

    otherCheck();
    cout << res;

    return 0;
}