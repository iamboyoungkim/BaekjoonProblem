#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    int arr[26] = {0};
    int max = 0;
    char res;
    getline(cin, s);
    
    std::transform(s.begin(), s.end(),s.begin(), ::toupper);
    
    for (int i = 0; i<s.length(); i++){
        arr[s.at(i)-65]++;
        if (max < arr[s.at(i)-65]){
            max = arr[s.at(i)-65];
            res = s.at(i);
        }
        else if (max == arr[s.at(i)-65]){
            res = '?';
        }
    }
    cout << res << endl;
    
    return 0;
}

