// 인접 리스트 기반 source

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
    cout << x << ' ';
    for(int i = 0; i<arr[x].size(); i++){
        int next = arr[x][i];
        if(check[next] == false) dfs(next);
    }
}

void bfs(int x){
    queue<int> q;
    memset(check, false, sizeof(check));
    check[x] = true;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int i=0; i<arr[cur].size(); i++) {
            int next = arr[cur][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    int n, m, v, from, to;
    cin >> n >> m >> v;
    for (int i = 0; i<m; i++){
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    for(int i = 1; i<=n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';
    return 0;
}
