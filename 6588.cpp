// 시간초과 뜰경우는 endl보다는 '\n' 사용하기
// 에라토스네스의 체 알고리즘 이용

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>

const int MAX = 1000000;
bool check[MAX+1]; // 지워졌으면 true
int prime[MAX];
int pn = 0; // 소수의 갯수

using namespace std;

int main(){
    for (int i = 2; i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i + i; j <= MAX; j += i) {
                check[j] = true;
            }
        }
    }
    while(true){
        int t;
        scanf("%d", &t);
        if (t == 0) break;
        for (int i = 0; i<pn; i++){
            if (check[t - prime[i]] == false) {
                cout << t << " = " << prime[i] << " + " << t - prime[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
