// 1. 문제를 이해하고 자신의 용어로 재정의 
// * 최단 경로 -> 다익스트라로 해결

// 2. 이 문제의 유형이 무엇인지 판단한다.
// * 다익스트라

// 3. 문제에 주어진 제약조건(범위 등)들을 고려하면서 자신이 생각한 유형으로 문제를 풀었을때의 시간복잡도를 계산한다. 만약, 자신이 생각한 방법으로 시간복잡도를 계산 했을때 시간초과가 발생할 것 같으면 다시 2번으로 돌아간다.

// * 시간복잡도 O(ElogV)
// * 최근 풀었던 문제들 (위상정렬, 다익스트라 등등…)이 어렵게 느껴져서 먼저 풀어보고, 인터넷 검색을 통해 코드 리팩토링을 함
// * priority_queue에서 cost 음수로 바꾸는 부분 참고!
// * 주의할 부분 코드에 주석 씀


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
    priority_queue<pair<int, int>> pq; //priority_queue 는 max heap
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        // Point 4. cost를 음수로 만들어주는 이유 : 거리가 작은 정점부터 꺼내기 위해
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i<graph[here].size(); i++){
            int there = graph[here][i].first;
            int nextDist = cost + graph[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there)); // 여기도 nextDist에 -붙임
            }
        }
    }
    return dist;
}


int main() {
    int v, e, start, from, to, cost;
    cin >> v >> e;
    cin >> start;

    // point 1. 정점번호 1부터 시작
    v++;
    
    // point 2. graph의 source vertex(코드에서는 from이라고 씀)에 destination과 cost를 pair로 넣어줌
    for (int i = 0; i<e; i++){
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }


    vector<int> res = dijkstra(start, v);
    
    // Point3. 각 정점을 순회하면서 출력!
    for (int i = 1; i<v; i++){
        if (res[i] == INFINITY) cout << "INF\n";
        else cout << res[i] << "\n";
    }


    return 0;
}
