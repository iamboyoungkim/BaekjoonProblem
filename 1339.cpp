#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;
/*
 문제 풀이 방법
 
 */
char alpha[256];
int calc(vector<string> &arr, vector<int> &d, vector<char> &letters){
    int sum = 0;
    int ls = letters.size();
    for (int i = 0; i<ls; i++){
        alpha[letters[i]] = d[i];
    }
    for (string s: arr){
        int tmp = 0;
        for (char x : s){
            tmp = tmp * 10 + alpha[x];
        }
        sum += tmp;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    vector<char> letters;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
        for (char x: arr[i]){
            letters.push_back(x);
        }
    }
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    vector<int> d;
    int ls = letters.size();
    for (int i = 9; i>9-ls; i--){
        d.push_back(i);
    }
    sort(d.begin(), d.end());
    int res = 0;
    do{
        int tmp = calc(arr, d, letters);
        if (tmp > res)
            res = tmp;
    } while(next_permutation(d.begin(), d.end()));
    cout << res << '\n';
    return 0;
}
