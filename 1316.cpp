#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    int cnt = t;
    for (int i = 0; i<t; i++){
        cin >> s;
        bool arr[26] = {false};
        for (int j = 1; j<s.length(); j++){
            if(s.at(j) != s.at(j-1)){
                if(arr[s.at(j)-97] == true){
                    cnt--;
                    break;
                }
                arr[s.at(j-1)-97] = true;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
