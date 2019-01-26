#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b,a%b);
}

int main(){
    int t;
    cin >> t;
    int num;
    int arr[101];
    while (t--){
        cin >> num;
        for (int i = 0; i< num; i++)
            cin >> arr[i];
        long long sum = 0;
        for (int i = 0; i < num-1; i++){
            for(int j = i+1; j<num; j++){
                sum += gcd(arr[i], arr[j]);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
