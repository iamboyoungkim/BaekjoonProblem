#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> arr(t);
    for (int i = 0; i<t; i++){
        cin >> arr[i];
    }
    if (prev_permutation(arr.begin(),arr.end())) {
        for (int i=0; i<t; i++) {
            cout << arr[i] << ' ';
        }
    } else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}
