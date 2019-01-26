#include <iostream>

using namespace std;

int main(){
    int n;
    int cnt = 0;
    int A, B, C, tmp;
    cin >> n;
    tmp = n;
    while (tmp != n || cnt==0){
        A = tmp / 10;
        B = tmp % 10;
        C = (A + B) % 10;
        A = B;
        B = C;
        tmp = A * 10 + B;
        cnt++;
    }
    cout << cnt << endl;
}
