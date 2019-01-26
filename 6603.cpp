#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
int main() {
    while(true){
        int k;
        cin >> k;
        if(k==0) break;
        vector<int> arr(k);
        for (int i = 0; i<k; i++){
            cin >> arr[i];
        }
        vector<int> d;
        for (int i=0; i<k-6; i++) {
            d.push_back(0);
        }
        for (int i=0; i<6; i++) {
            d.push_back(1);
        }
        vector<vector<int>> res;
        do{
            vector<int> current;
            for(int i = 0; i<k; i++){
                if(d[i] == 1) current.push_back(arr[i]);
            }
            res.push_back(current);
        } while(next_permutation(d.begin(), d.end()));
        sort(res.begin(), res.end());
        for (auto &v : res){
            for(int i = 0; i<v.size(); i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
*/

vector<int> lotto;
void solve(vector<int> &a, int index, int cnt) {
    if (cnt == 6) {
        for (int num : lotto) {
            printf("%d ",num);
        }
        printf("\n");
        return;
    }
    if (a.size() == index) return;
    lotto.push_back(a[index]);
    solve(a,index+1,cnt+1);
    lotto.pop_back();
    solve(a,index+1,cnt);
}
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        solve(a, 0, 0);
        cout << '\n';
    }
    return 0;
}
