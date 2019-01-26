#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;
/*
 문제 풀이 방법

 */
int main() {
    int t;
    cin >> t;
    while (t--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool flag = false;
        for (int j = x; j<m*n; j+=m){
            if (j%n == y){
                cout << j+1 << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << '\n';
    }
    return 0;
}
