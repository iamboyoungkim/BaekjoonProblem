#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int num[10];
int check[10];

void go(int idx, int n, int m) {
    if (idx == m) {
        for (int i=0; i<m; i++) {
            cout << num[arr[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i=0; i<n; i++) {
        if (check[i]) continue;
        check[i] = true;
        arr[idx] = i;
        go(idx+1, n, m);
        check[i] = false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num,num+n);
    go(0,n,m);
    return 0;
}