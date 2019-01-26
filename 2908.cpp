#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int num1 = atoi(a.c_str());
    int num2 = atoi(b.c_str());
    
    cout << max(num1, num2) << endl;
    return 0;
}

