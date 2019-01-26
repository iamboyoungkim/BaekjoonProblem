#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int tnum, n;
    string s;
    cin >> tnum;
    for (int i = 0; i<tnum; i++){
        cin >> n >> s;
        for (int j = 0; j < s.length(); j++)
            for (int k = 0; k<n; k++)
                printf("%c", s.at(j));
        printf("\n");
    }
    return 0;
}

