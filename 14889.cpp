#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

// brute force 풀이

// int main() {
//     int n;
//     cin >> n;
//     int a[n][n];
//     for (int i = 0; i<n; i++){
//         for (int j= 0; j<n; j++){
//             cin >> a[i][j];
//         }
//     }
//     vector<int> b(n);
//     for (int i = 0; i<n/2; i++){
//         b[i] = 1;
//     }
//     for (int i = n/2; i<n; i++){
//         b[i] = 0;
//     }
//     sort(b.begin(), b.end());
//     int res = 300000000;
//     do{
//         vector<int> team1;
//         vector<int> team2;
//         for (int i = 0; i<n; i++){
//             if (b[i] == 0) team1.push_back(i);
//             else team2.push_back(i);
//         }
//         int sum1 = 0;
//         int sum2 = 0;
//         for (int i = 0; i<n/2; i++){
//             for (int j = 0; j<n/2; j++){
//                 if (i==j) continue;
//                 sum1 += a[team1[i]][team1[j]];
//                 sum2 += a[team2[i]][team2[j]];
//             }
//         }
//         int diff = abs(sum1-sum2);
//         if ( res > diff) res = diff;
//     } while (next_permutation(b.begin(), b.end()));
//     cout << res << '\n';
    
//     return 0;
// }



// back tracking 풀이
/*
int n;
int a[20][20];
int go(int idx, vector<int> &team1, vector<int> &team2){
    // 정답을 찾은 경우
    if (idx == n){
        if (team1.size() != n/2) return -1;
        if (team2.size() != n/2) return -1;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i<n/2; i++){
            for (int j = 0; j<n/2; j++){
                if (i==j) continue;
                sum1 += a[team1[i]][team1[j]];
                sum2 += a[team2[i]][team2[j]];
            }
        }
        int diff = abs(sum1-sum2);
        return diff;
    }
    // 틀린 경우
    if (team1.size() > n/2) return -1;
    if (team2.size() > n/2) return -1;
    
    // 다음 단계 탐색
    int res = -1;
    team1.push_back(idx);
    int tmp1 = go(idx+1, team1, team2);
    if ( res == -1 || tmp1 != -1 && res > tmp1){
        res = tmp1;
    }
    team1.pop_back();
    team2.push_back(idx);
    int tmp2 = go(idx+1, team1, team2);
    if ( res == -1 || tmp2 != -1 && res > tmp2){
        res = tmp2;
    }
    team2.pop_back();
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i<n; i++){
        for (int j= 0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    vector<int> team1;
    vector<int> team2;
    cout << go(0, team1, team2) << '\n';
    return 0;
}
*/
// 비트마스크 풀이

int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int res = -1;
    for (int i = 0; i<(1<<n); i++){ // 0부터 1이 n개 있는 수까지 순회
        // 미리 1의 갯수를 검사한 다음에, n/2가 아니면 그냥 건너뛰는 방식으로 시간을 절약
        int cnt = 0;
        for (int j = 0; j<n; j++){
            if (i&(1<<j)) cnt += 1;
        }
        if (cnt != n/2) continue;
        vector<int> team1, team2;
        for (int j = 0; j<n; j++){
            if (i&(1<<j)) team1.push_back(j); // 1이 있으면 team1에
            else team2.push_back(j); // 1이 없으면 team2에
        }
        int sum1 = 0;
        int sum2 = 0;
        for (int s1 = 0; s1<n/2; s1++){
            for (int s2 = 0; s2<n/2; s2++){
                if (s1 == s2) continue;
                sum1 += arr[team1[s1]][team1[s2]];
                sum2 += arr[team2[s1]][team2[s2]];
            }
        }
        int diff = abs(sum1-sum2);
        if ( res == -1 || res > diff) res = diff;
    }
    cout << res << '\n';
    return 0;
}
