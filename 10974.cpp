#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> arr(t);
    for (int i = 0; i<t; i++){
        arr[i] = i+1;
    }
    do{
        for (int i = 0; i<t; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(arr.begin(), arr.end()));
    return 0;
}
