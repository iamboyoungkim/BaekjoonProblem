#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int> &a, vector<int> &b){
    int ans = a[0];
    for (int i = 1; i<a.size(); i++){
        if (b[i-1] == 0) {
            ans = ans + a[i];
        } else if (b[i-1] == 1) {
            ans = ans - a[i];
        } else if (b[i-1] == 2) {
            ans = ans * a[i];
        } else {
            ans = ans / a[i];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    vector<int> oper;
    for (int i=0; i<4; i++) {
        int cnt;
        cin >> cnt;
        for (int k=0; k<cnt; k++) {
            oper.push_back(i);
        }
    }
    vector<int> result;
    do {
        int temp = calc(arr, oper);
        result.push_back(temp);
    } while (next_permutation(oper.begin(), oper.end()));

    auto ans = minmax_element(result.begin(), result.end());
    cout << *ans.second << '\n'; // 최댓값
    cout << *ans.first << '\n'; // 최솟값
    return 0;
}