#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[4][4];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            scanf("%1d", &arr[i][j]); //%1d를 이용해 붙어있는 수를 하나씩 입력받기
        }
    }
    int res = 0;
    for (int s = 0; s<(1<<n*m); s++){ //0부터 n*m까지 모든 경우의 수
        int sum = 0;
        // 0은 가로
        for (int i = 0; i<n; i++){
            int cur = 0;
            for (int j = 0; j<m; j++){
                int k = i*m+j;
                if ((s & (1<<k)) == 0) cur = cur * 10 + arr[i][j];
                else { // 세로가 나옴 -> 끝남 -> 지금까지의 합을 더해주고 cur을 0으로
                    sum += cur;
                    cur = 0;
                }
            }
            // 세로가 나오지 않고 가로 한 줄이 끝난 경우
            sum += cur;
        }
        // 1은 세로
        for (int j = 0; j<m; j++){
            int cur = 0;
            for (int i = 0; i<n; i++){
                int k = i*m+j;
                if ((s & (1<<k)) != 0) cur = cur * 10 + arr[i][j];
                else { // 가로가 나옴 -> 끝남 -> 지금까지의 합을 더해주고 cur을 0으로
                    sum += cur;
                    cur = 0;
                }
            }
            // 가로가 나오지 않고 가로 한 줄이 끝난 경우
            sum += cur;
        }
        res = max(res, sum);
    }
    cout << res << '\n';
    return 0;
}
