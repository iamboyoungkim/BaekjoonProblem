#include <iostream>

using namespace std;

int arr[10001];

int dn(int num){
    int res = num;
    while (num != 0){
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main(void){
    for(int i=1; i<10001; i++){
        int idx = dn(i);
        if(idx < 10001){
            arr[idx] = 1;
        }
    }
    for(int i=1; i<10001; i++){
        if(!arr[i]) cout<<i<<endl;
    }
    return 0;
}
