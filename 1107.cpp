#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;
/*
 문제 풀이 방법
 1. 채널 C 정하기
 2. C중 고장난 버튼 있는지 확인
 3. 고장난 버튼이 포함되어 있지 않다면 |C-N| 계산해서 +혹은 -횟수 구하기
 */

bool broken[10];
int channel[1000001];

int possible(int x){
    int len = 0;
    if (x == 0) {
        if (broken[x]) return 0;
        else return 1;
        
    }
    while (x > 0){
        if (broken[x%10]) return 0;
        len += 1;
        x /= 10;
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i<m; i++){
        int x;
        cin >> x;
        broken[x] = true;
    }
    int channel = abs(n-100);
    for (int i = 0; i<1000000; i++){
        int c = i;
        int len = possible(c);
        if (len > 0){
            int press = abs(c-n);
            if (channel > len + press) channel = len + press;
        }
    }
    cout << channel;
    return 0;
}
