#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> calc(vector<int> &arr, int index, int cur, int plus, int minus, int mul, int div) {
    if (index == arr.size()) {
        return make_pair(cur, cur);
    }
    vector<pair<int,int>> res;
    if (plus > 0) {
        res.push_back(calc(arr,index+1,cur+arr[index],plus-1,minus,mul,div));
    }
    if (minus > 0) {
        res.push_back(calc(arr,index+1,cur-arr[index],plus,minus-1,mul,div));
    }
    if (mul > 0) {
        res.push_back(calc(arr,index+1,cur*arr[index],plus,minus,mul-1,div));
    }
    if (div > 0) {
        res.push_back(calc(arr,index+1,cur/arr[index],plus,minus,mul,div-1));
    }
    
    auto ans = res[0];
    for (auto tmp: res){
        if (ans.first < tmp.first) ans.first = tmp.first;
        if (ans.second > tmp.second) ans.second = tmp.second;
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
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;
    
    auto res = calc(arr, 1, arr[0], plus, minus, mul, div);
    cout << res.first << '\n';
    cout << res.second << '\n';
    
    return 0;
}
