#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> arr[1001];
bool check[1001];

void dfs(int x){
    check[x] = true;
    for(int i = 0; i<arr[x].size(); i++){
        int next = arr[x][i];
        if(check[next] == false) dfs(next);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    int com = 0;
    for (int i=1; i<=n; i++) {
        if (check[i] == false) {
            dfs(i);
            com += 1;
        }
    }
    cout << com << '\n';
    return 0;
}
