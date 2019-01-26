#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
int check[9];

void go(int n, int m, int idx, int start){
    if (idx == m){
        for(int i = 0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = start; i<=n; i++){
        //if(check[i]) continue;
        check[i] = true;
        arr[idx] = i;
        go(n, m, idx+1,i);
        check[i] = false;
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    go(n,m,0,1);
    return 0;
}
