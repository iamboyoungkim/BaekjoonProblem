#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int N, L; // L은 경사로의 최대 길이
int map[101][101];
int res = 0;

void checkRow(int row) {
    int compare = map[row][0];
    bool isSlides[101] = { false, };
    for (int i = 0; i<N; i++){
        // 앞과 다르면
        if ( compare != map[row][i] ) {
            // 경사로를 놓을 수 없음
            if ( abs(map[row][i] - compare) > 1) return;
            // 경사로 가능 && 앞쪽이 더 큰 경우
            else if (compare - map[row][i] == 1) {
                int tmp = -1;
                for (int j = i; j<L+i; j++){
                    if ( j >= N || isSlides[j] == true) return;
                    isSlides[j] = true;
                    if (tmp == -1) {
                        tmp = map[row][j];
                        continue;
                    }
                    if (tmp != -1 && map[row][j] != tmp) return;
                }
                i = i+L-1;
                if (i >= N) break;
            }
            // 경사로 가능 && 뒷쪽이 더 큰 경우
            else if (map[row][i] - compare == 1) {
                int tmp = -1;
                for (int j = i-1; j>=i-L; j--){
                    if (j < 0 || isSlides[j] == true) return;
                    isSlides[j] = true;
                    if (tmp == -1) {
                        tmp = map[row][j];
                        continue;
                    }
                    if (tmp != -1 && map[row][j] != tmp) return;
                }
            }
            compare = map[row][i];
        }
    }
    res += 1;
}

void checkCol(int col) {
    int compare = map[0][col];
    bool isSlides[101] = { false, };
    for (int i = 0; i<N; i++){
        // 앞과 다르면
        if ( compare != map[i][col] ) {
            // 경사로를 놓을 수 없음
            if ( abs(map[i][col] - compare) > 1) return;
                // 경사로 가능 && 앞쪽이 더 큰 경우
            else if (compare - map[i][col] == 1) {
                int tmp = -1;
                for (int j = i; j<L+i; j++){
                    if ( j >= N || isSlides[j] == true) return;
                    isSlides[j] = true;
                    if (tmp == -1) {
                        tmp = map[j][col];
                        continue;
                    }
                    if (tmp != -1 && map[j][col] != tmp) return;
                }
                i = i+L-1;
                if (i >= N) break;
            }
                // 경사로 가능 && 뒷쪽이 더 큰 경우
            else if (map[i][col] - compare == 1) {
                int tmp = -1;
                for (int j = i-1; j>=i-L; j--){
                    if (j < 0 || isSlides[j] == true) return;
                    isSlides[j] = true;
                    if (tmp == -1) {
                        tmp = map[j][col];
                        continue;
                    }
                    if (tmp != -1 && map[j][col] != tmp) return;
                }
            }
            compare = map[i][col];
        }
    }
    res += 1;
}


int main() {
    cin >> N >> L;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            cin >> map[i][j];
        }
    }
    for (int i = 0; i<N; i++){
        checkRow(i);
        checkCol(i);
    }
    cout << res << endl;
    return 0;
}