#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mod = 10007;
int d[1001][10]; // 길이, 마지막수 저장

int main() {
    int n;
    cin >> n;
    // 길이 1인 경우 초기화. 0으로 시작하는 수 있음
    for(int i = 0; i<=9; i++){
        d[1][i] = 1;
    }
    // 길이가 2 이상인 경우
    for (int i = 2; i<=n; i++){
        for (int j = 0; j<=9; j++){
            for(int k = 0; k<=j; k++){
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }
    // 마지막 수가 0부터 9까지 모두 가능하므로 값을 모두 더해줌
    int ans = 0;
    for (int i = 0; i <= 9; i++){
        ans += d[n][i];
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}
