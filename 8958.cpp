#include <iostream>
#include <cstring>

using namespace std;

char s[81];

int main(){
    int n, tmp, sum;
    cin >> n;
    for (int i = 0; i < n; i++) {
        sum = 0;
        tmp = 1;
        cin >> s;
        for (int j = 0; j < strlen(s); j++){
            if (s[j] == 'O'){
                sum += tmp;
                tmp++;
            }
            if (s[j] == 'X') tmp = 1;
        }
        cout << sum << endl;
    }
}
