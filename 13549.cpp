// queue 사용

/*
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];

int main() {
    int n,k;
    cin >> n >> k;
    check[n] = true;
    dist[n] = 0;
    queue<int> q; // 거리 같음
    queue<int> next_q; // 거리가 +1됨
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (now * 2 <  MAX){
            if(check[now*2] == false){
                q.push(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now];
            }
        }
        if(now - 1 >= 0){
            if(check[now-1] == false){
                next_q.push(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now] + 1;
            }
        }
        if (now + 1 < MAX){
            if(check[now+1] == false){
                next_q.push(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now] + 1;
            }
        }
        if (q.empty()) {
            q = next_q; // 현재 큐는 다음 큐로
            next_q = queue<int>(); // 다음 큐는 새로 만들어줌
        }
    }
    cout << dist[k] << '\n';
    return 0;
}

*/



// deque 사용
// 순간 이동은 덱의 앞에, 일반 이동은 뒤에 넣기

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];

int main() {
    int n,k;
    cin >> n >> k;
    check[n] = true;
    dist[n] = 0;
    deque<int> q; // 거리 같음
    q.push_back(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop_front();
        
        if (now * 2 <  MAX){
            if(check[now*2] == false){
                q.push_front(now*2);
                check[now*2] = true;
                dist[now*2] = dist[now];
            }
        }
        if(now - 1 >= 0){
            if(check[now-1] == false){
                q.push_back(now-1);
                check[now-1] = true;
                dist[now-1] = dist[now] + 1;
            }
        }
        if (now + 1 < MAX){
            if(check[now+1] == false){
                q.push_back(now+1);
                check[now+1] = true;
                dist[now+1] = dist[now] + 1;
            }
        }
    }
    cout << dist[k] << '\n';
    return 0;
}
