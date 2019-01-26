#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check(string &password){
    int jaeum = 0;
    int moeum = 0;
    for (char x : password){
        if (x == 'a' || x=='e' || x == 'i' || x == 'o' || x == 'u') moeum += 1;
        else jaeum += 1;
    }
    if (jaeum >= 2 && moeum >= 1) return true;
    else return false;
}

void go(int n, vector<char> &alpha, string password, int i) {
    if (n == password.length()) {
        if (check(password)) cout << password << '\n';
        return;
    }
    if (i == alpha.size()) return;
    go(n, alpha, password+alpha[i], i+1);
    go(n, alpha, password, i+1);
}

int main(){
    int length, c;
    cin >> length >> c;
    vector<char> alpha(c);
    for (int i = 0; i<c; i++){
        cin >> alpha[i];
    }
    sort(alpha.begin(), alpha.end());
    go(length, alpha, "", 0);
    return 0;
}
