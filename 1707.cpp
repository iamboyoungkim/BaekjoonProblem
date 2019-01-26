#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> arr[20001];
int color[20001];

void dfs(int x, int c){
    color[x] = c;
    for(int i = 0; i<arr[x].size(); i++){
        int next = arr[x][i];
        if(color[next] == 0) dfs(next, 3-c); // color가 1이나 2이기 때문에
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int v,e;
        cin >> v >> e;
        for(int i = 1; i<=v; i++){
            arr[i].clear();
            color[i] = 0;
        }
        for(int i = 0; i<e; i++){
            int from, to;
            cin >> from >> to;
            arr[from].push_back(to);
            arr[to].push_back(from);
        }
        for (int i=1; i<=v; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        bool ok = true;
        for (int i=1; i<=v; i++) {
            for (int k=0; k<arr[i].size(); k++) {
                int j = arr[i][k];
                if (color[i] == color[j]) {
                    ok = false;
                }
            }
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
