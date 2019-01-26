#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    int res;
    int arr[10] = {0};
    cin >> a >> b >> c;
    res = a*b*c;
    
    while(res != 0){
        arr[res % 10] +=1;
        res /= 10;
    }
    
    for (int i = 0;i<10;i++){
        cout << arr[i] << endl;
    }
}
