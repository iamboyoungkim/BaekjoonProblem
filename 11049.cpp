#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int min (int a, int b) {
    if (a>b) return b;
    else return a;
}

int N;
int dp[501][501];
int d[501];

int main(){

    cin >> N;
    cin >> d[0] >> d[1];

    for (int n = 1; n < N - 1; n++)
        cin >> d[n] >> d[n + 1];

    cin >> d[N - 1] >> d[N];

    for (int dia = 0; dia < N; dia++){
        for (int n = 1; n <= N - dia; n++){
            int m = n + dia;
            if (n == m){
                dp[n][m] = 0;
                continue;
            }
            dp[n][m] = 987654321;

            for (int k = n; k < m; k++){
                dp[n][m] = min(dp[n][m], dp[n][k] + dp[k + 1][m] + d[n - 1] * d[k] * d[m]);
            }
        }
    }
    cout << dp[1][N];
    return 0;

}
