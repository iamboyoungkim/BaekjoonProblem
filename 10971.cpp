#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w[11][11];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> w[i][j];
        }
    }
    vector<int> d(n);
    for(int i = 0; i<n; i++){
        d[i] = i;
    }
    int min = 987654321;
    do{
        bool chk = true;
        int sum = 0;
        for(int i = 0; i<n-1; i++){
            if(w[d[i]][d[i+1]] == 0) chk = false;
            sum += w[d[i]][d[i+1]];
        }
        if(chk && w[d[n-1]][d[0]] != 0){
            sum += w[d[n-1]][d[0]];
            if (min > sum) min = sum;
        }
        
    } while(next_permutation(d.begin(), d.end()));
    cout << min << '\n';
    
    return 0;
}
