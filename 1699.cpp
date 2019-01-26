#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// d[i] : i를 제곱수로 나타냈을 때, 필요한 항의 최소 갯수
// n - i^2 + i^2 = n

int d[100001];

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        d[i] = i;
        for (int j=1; j*j <= i; j++) {
            if (d[i] > d[i-j*j]+1) {
                d[i] = d[i-j*j]+1;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
