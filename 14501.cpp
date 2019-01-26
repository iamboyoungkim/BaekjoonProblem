#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int res = 0;
int t[16];
int p[16];

void go(int day, int sum){
    if (day == n+1){
        if (res < sum) res = sum;
        return;
    }
    if (day > n+1) return;
    go(day+t[day], sum+p[day]);
    go(day+1, sum);
    
}
int main(){
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> t[i] >> p[i];
    }
    go(1,0);
    cout << res << '\n';
    return 0;
}
