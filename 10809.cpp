#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int alpha[26];
    char s[101];
    int idx;
    
    cin >> s;
    
    for (int i = 0; i<26; i++) alpha[i] = -1;
    
    for (int i = 0; s[i] != '\0'; i++){
        idx = s[i]-97;
        if (alpha[idx] == -1) alpha[idx] = i;
    }
    
    for (int i = 0; i<26; i++) printf("%d ", alpha[i]);
}

