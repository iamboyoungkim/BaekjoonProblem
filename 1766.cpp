#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    int indegree[32001] = {0};
    vector<int> next[32001];
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N >> M;

    for (int i = 0; i<M; i++){
        int a,b;
        cin >> a >> b;
        next[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i<=N; i++){
        if (!indegree[i]) pq.push(i);
    }

    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        cout << now << " ";
        for (auto x: next[now]){
            if (--indegree[x] == 0) {
                pq.push(x);
            }
        }
    }
    return 0;
}