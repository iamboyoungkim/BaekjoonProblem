#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
bool check[9];

void go(int n, int m, int idx){
    if (idx == m){
        for(int i = 0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i<=n; i++){
        if(check[i]) continue;
        check[i] = true;
        arr[idx] = i;
        go(n, m, idx+1);
        check[i] = false;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    go(n,m,0);
    return 0;
}
