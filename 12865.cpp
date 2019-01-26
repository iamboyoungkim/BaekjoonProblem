#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int d[101][100001];

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for (int i = 1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i<=n; i++){
        for (int j = 0; j<k; j++){
            d[i][j] = 0;
        }
    }
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=k; j++){
            if (w[i] > j) {
                d[i][j] = d[i-1][j];
            }
            else {
                d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout << d[n][k] << '\n';
    return 0;
}
