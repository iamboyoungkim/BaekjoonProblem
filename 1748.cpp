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
 수의 자릿수별로 나누어 문제 해결
 N = 120일 경우
 1~9 / 10~99 / 100~120
 */
int main() {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 1, len = 1; i<=n; i*=10, len++){
        int end = i*10-1;
        if (end > n) end = n;
        res += (long long)(end - i + 1) * len;
    }
    cout << res;
    return 0;
}