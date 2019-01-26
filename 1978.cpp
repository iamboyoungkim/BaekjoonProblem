#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int k = 0, cnt = 0;
    for (int i = 0; i<n; i++){
        for (int j = 1; j<=arr[i] ; j++){
            if (arr[i] % j == 0) k++;
        }
        if (k == 2){
            cnt++;
            k = 0;
        }
        k = 0;
    }
    cout << cnt << '\n';
    return 0;
}
