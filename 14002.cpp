#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[1001];
int d[1001]; // a[i]를 마지막으로 하는 가장 긴 증가하는 부분의 수열 길이
int v[1001]; // a[i]앞에 와야 하는 수의 인덱스

void go(int p) {
    // ? -> ? -> ... a[v[p]] -> a[p]
    // ---------------------
    //        go(v[p]);
    if (p == -1) {
        return ;
    }
    go(v[p]);
    cout << a[p] << ' ';
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        d[i] = 1;
        v[i] = -1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[i] < d[j]+1) {
                d[i] = d[j]+1;
                v[i] = j;
            }
        }
    }
    int ans = d[0];
    int p = 0;
    for (int i=0; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
            p = i;
        }
    }
    cout << ans << '\n';
    go(p);
    cout << '\n';
    return 0;
}
