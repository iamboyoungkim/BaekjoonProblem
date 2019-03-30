#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define INFINITY 987654321

using namespace std;

vector<pair<int, int>> graph[300001];

vector<int> dijkstra(int src, int vertex) {
    vector<int> dist(vertex, INFINITY);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i<graph[here].size(); i++){
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    int v, e, start, from, to, cost;
    cin >> v >> e;
    cin >> start;

    v++;

    for (int i = 0; i<e; i++){
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }

    vector<int> res = dijkstra(start, v);

    for (int i = 1; i<v; i++){
        if (res[i] == INFINITY) cout << "INF\n";
        else cout << res[i] << "\n";
    }

    return 0;
}