#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int calculate(vector<int> &arr){
    int sum = 0;
    for (int i = 0; i<arr.size()-1; i++){
        sum += abs(arr[i] - arr[i+1]);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    vector<int> arr(t);
    for (int i = 0; i<t; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = 0;
    do {
        res = max(res, calculate(arr));
    } while(next_permutation(arr.begin(), arr.end()));
    
    cout << res << '\n';
    return 0;
}
