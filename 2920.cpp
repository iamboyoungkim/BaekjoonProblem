#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int arr[8];
    int asc = 0;
    int des = 0;
    for ( int i = 0;i <8; i++)
        cin >> arr[i];
    for ( int i = 0; i<7; i++){
        if (arr[i+1]-arr[i] == 1) asc++;
        else if (arr[i+1]-arr[i] == -1 ) des++;
    }
    if(asc == 7) cout << "ascending" << endl;
    else if (des == 7) cout << "descending" << endl;
    else cout << "mixed" << endl;
}
