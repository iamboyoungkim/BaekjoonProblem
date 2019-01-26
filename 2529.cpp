#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;


// brute force 풀이
/*
 문제 풀이 방법
 1. 어떤 수를 사용할지 결정
 2. 순열 이용
*/

// bool check(vector<int> &numbers, vector<char> &a){
//     for (int i = 0; i<a.size(); i++){
//         // 틀린 경우 check (나머지는 true)
//         if (a[i] == '<' && numbers[i] > numbers[i+1]) return false;
//         if (a[i] == '>' && numbers[i] < numbers[i+1]) return false;
//     }
//     return true;
// }

// int main() {
//     int k;
//     cin >> k;
//     vector<char> arr(k);
//     for (int i = 0; i<k; i++){
//         cin >> arr[i];
//     }
//     vector<int> small(k+1);
//     vector<int> large(k+1);
//     for (int i = 0; i<k+1; i++){
//         small[i]= i;
//         large[i] = 9-i;
//     }
//     do{
//         if (check(small, arr))
//             break;
//     } while (next_permutation(small.begin(), small.end()));
//     do{
//         if (check(large, arr))
//             break;
//     } while (prev_permutation(large.begin(), large.end()));
    
//     for (int i = 0; i<large.size(); i++){
//         cout << large[i];
//     }
//     cout << '\n';
//     for(int i = 0; i<small.size(); i++){
//         cout << small[i];
//     }
//     cout << '\n';
    
//     return 0;
// }



// back tracking 풀이
int n;
char a[11];
vector<string> res;
bool check[10];

bool ok(char c1, char c2, char op){
    if (op == '<') {
        if (c1 < c2) return true;
        return false;
    }
    if (op == '>') {
        if (c1 > c2) return true;
        return false;
    }
    return true;
}

void go(int idx, string num){
    // 정답인 경우
    if (idx == n+1){
        res.push_back(num);
        return;
    }
    // 다음 스텝
    for (int i = 0; i<=9; i++){
        if (check[i]) continue;
        if (idx == 0 || ok(num[idx-1], i+'0', a[idx-1])){ // +'0' 은 지금 i값의 character형을 나타냄
            check[i] = true;
            go(idx+1, num+to_string(i));
            check[i] = false;
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    go(0, "");
    auto p = minmax_element(res.begin(), res.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}
