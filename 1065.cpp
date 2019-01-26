#include <iostream>

using namespace std;

int main() {
    int n, cnt;
    int a, b, c;
    cin >> n;
    
    if (n < 100) cout << n << endl;
    
    else {
        cnt = 0;
        for (int i = 100; i <= n; i++){
            a = i / 100;
            b = (i / 10) % 10;
            c = i % 10;
            
            if ((a - b) == (b - c)) cnt++;
        }
        cout << cnt+99 << endl;
    }
    return 0;
}
