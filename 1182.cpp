#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int a[20];
int main() {
    int n,s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i=1; i<(1<<n); i++) {
        int sum = 0;
        for (int k=0; k<n; k++) {
            if (i&(1<<k)) {
                sum += a[k];
            }
        }
        if (sum == s) {
            res += 1;
        }
    }
    cout << res << '\n';
    return 0;
}