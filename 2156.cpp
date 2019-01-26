#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 1. 2차원 배열로 푸는 법
 d[i][j] = a[1]~a[i]있을 떄 포도주를 마신 최대값
 j = 0 -> i번째 마시지 X -> max(d[i-1][0], d[i-1][1], d[i-1][2])
 j = 1 -> i번째 마심 O && 연속 1 -> d[i-1][0] + a[i]
 j = 2 -> i번째 마심 O && 연속 2 -> d[i-1][1] + a[i]
 
 2. 1차원 배열로 푸는 법
 d[i] = a[1]~a[i]있을 떼 포도주를 마신 최대값
 0번 연속 -> a[i]를 마시지 않음 -> d[i-1]
 1번 연속 -> a[i-1]을 마시지 않음 -> d[i-2] + a[i]
 2번 연속 -> a[i-1]은 마시고, a[i-2]를 마시지 않음 -> d[i-3] + a[i-1] + a[i]
 */

int a[10001];
int d[10001];

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    d[1] = a[1];
    d[2] = a[1]+a[2];
    for (int i=3; i<=n; i++) {
        d[i] = d[i-1];
        if (d[i] < d[i-2] + a[i]) {
            d[i] = d[i-2] + a[i];
        }
        if (d[i] < d[i-3] + a[i] + a[i-1]) {
            d[i] = d[i-3] + a[i] + a[i-1];
        }
    }
    cout << d[n] << '\n';
    return 0;
}
