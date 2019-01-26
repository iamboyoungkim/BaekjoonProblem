#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int d[11];

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        memset(d, 0, sizeof(d));
        d[0] = 1;
        
        for(int i = 1; i <= n; i++){
            if( i-1 >= 0) d[i] += d[i-1];
            if( i-2 >= 0) d[i] += d[i-2];
            if( i-3 >= 0 ) d[i] += d[i-3];
        }
        cout << d[n] << '\n';
    }
    return 0;
}



/*
#include <cstdio>
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int ans = 0;
        int n;
        scanf("%d",&n);
        for (int l1=1; l1<=3; l1++) {
            if (l1 == n) {
                ans += 1;
            }
            for (int l2=1; l2<=3; l2++) {
                if (l1+l2 == n) {
                    ans += 1;
                }
                for (int l3=1; l3<=3; l3++) {
                    if (l1+l2+l3 == n) {
                        ans += 1;
                    }
                    for (int l4=1; l4<=3; l4++) {
                        if (l1+l2+l3+l4 == n) {
                            ans += 1;
                        }
                        for (int l5=1; l5<=3; l5++) {
                            if (l1+l2+l3+l4+l5 == n) {
                                ans += 1;
                            }
                            for (int l6=1; l6<=3; l6++) {
                                if (l1+l2+l3+l4+l5+l6 == n) {
                                    ans += 1;
                                }
                                for (int l7=1; l7<=3; l7++) {
                                    if (l1+l2+l3+l4+l5+l6+l7 == n) {
                                        ans += 1;
                                    }
                                    for (int l8=1; l8<=3; l8++) {
                                        if (l1+l2+l3+l4+l5+l6+l7+l8 == n) {
                                            ans += 1;
                                        }
                                        for (int l9=1; l9<=3; l9++) {
                                            if (l1+l2+l3+l4+l5+l6+l7+l8+l9 == n) {
                                                ans += 1;
                                            }
                                            for (int l0=1; l0<=3; l0++) {
                                                if (l1+l2+l3+l4+l5+l6+l7+l8+l9+l0 == n) {
                                                    ans += 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/