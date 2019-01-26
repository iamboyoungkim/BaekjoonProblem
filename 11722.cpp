// LIS 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> d(n+1);
    for (int i=n; i>=1; i--) {
        d[i] = 1; //혼자 있는 경우
        for (int j=i+1; j<=n; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    int ans = d[1];
    for (int i = 2; i<n; i++){
        if (ans < d[i])
            ans = d[i];
    }
    cout << *max_element(d.begin(),d.end()) << '\n';
    return 0;
}
