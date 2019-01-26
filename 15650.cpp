#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int arr[9];

void go(int n, int m, int idx, int start){
    if (idx == m){
        for(int i = 0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i<=n; i++){
        arr[idx] = i;
        go(n, m, idx+1, i+1);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    go(n,m,0,1);
    return 0;
}
*/

int a[10];
void go(int index, int selected, int n, int m) {
    if (selected == m) {
        for (int i=0; i<m; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (index > n) return;
    a[selected] = index;
    go(index+1, selected+1, n, m);
    a[selected] = 0;
    go(index+1, selected, n, m);
}
int main() {
    int n, m;
    cin >> n >> m;
    go(1, 0, n, m);
    return 0;
}