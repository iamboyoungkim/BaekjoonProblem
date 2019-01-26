#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }
    vector<int> d(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            d[i] = max(d[i],d[i-j]+p[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}
