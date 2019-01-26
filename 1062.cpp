#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

int count(int mask, vector<int> &words){
    int cnt = 0;
    for (int word : words){
        if ((word & ((1<<26)-1-mask)) == 0){
            cnt += 1;
        }
    }
    return cnt;
}

int go(int idx, int k, int mask, vector<int> &words){ //mask : 배운 알파벳
    if (k < 0) return 0;
    if (idx == 26)
        return count(mask, words); // 알파벳 끝까지 다 돌았으면 몇 개의 단어를 알 수 있는지 출력해야 함.
    int res = -1;
    int tmp = go(idx+1, k-1, mask|(1<<idx), words); //배운 알파벳에 현재 idx추가
    if (res < tmp) res = tmp;
    // 아래 경우에만 배우지 않을 수 있음 (anta, tica는 꼭 배워야 하기 때문에)
    if (idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a'){
        tmp = go(idx+1, k, mask, words);
        if (res < tmp) res = tmp;
    }
    return res;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> words(n); //주어진 단어
    for (int i = 0; i<n; i++){
        string s;
        cin >> s;
        for (char x : s){
            words[i] |= (1 << (x - 'a'));  // 배워야 할 알파벳이 몇번째 알파벳인가? -> words라는 배열에 추가
        }
    }
    cout << go(0, k, 0, words) << '\n';
    return 0;
}
