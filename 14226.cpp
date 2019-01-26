#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dist[1001][1001];

int main() {
    int n;
    cin >> n;
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    dist[1][0] = 0;
    while (!q.empty()){
        int s,c;
        tie(s,c) = q.front();
        q.pop();
        // 복사
        if(dist[s][s] == -1){
            dist[s][s] = dist[s][c] + 1;
            q.push(make_pair(s, s));
        }
        // 붙여넣기
        if(s+c <= n && dist[s+c][s] == -1){
            dist[s+c][s] = dist[s][c] + 1;
            q.push(make_pair(s+c, s));
        }
        // 삭제
        if(s-1 > 0 && dist[s-1][s] == -1){
            dist[s-1][c] = dist[s][c] + 1;
            q.push(make_pair(s-1, s));
        }
        int ans = -1;
        for(int i = 0; i<=n; i++){
            if(dist[n][i] != -1){
                if (ans == -1 || ans > dist[n][i]){
                    ans = dist[n][i];
                }
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}
