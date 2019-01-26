#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int n,k;
    int res = 0;
    vector<int> arr(n+1);
    cin >> n >> k;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for (int i = n-1; i>=0; i--) {
        res += k / arr[i];
        k %= arr[i];
    }
    cout << res << '\n';
    return 0;
}
