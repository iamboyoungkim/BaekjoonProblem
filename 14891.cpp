#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int topni[5][8];
bool isVisit[5];
vector<pair<int, int> > rotateVec;

int rotateTopni(int idx, int direction) {
    isVisit[idx] = true;
    int tmp1 = topni[idx][2];
    int tmp2 = topni[idx][6];
    // 시계방향
    if (direction == 1) {
        int tmp = topni[idx][7];
        for (int i = 6; i>=0; i--){
            topni[idx][i+1] = topni[idx][i];
        }
        topni[idx][0] = tmp;
    }
    // 반시계 방향
    else if (direction == -1){
        int tmp = topni[idx][0];
        for (int i = 1; i<8; i++){
            topni[idx][i-1] = topni[idx][i];
        }
        topni[idx][7] = tmp;
    }
    if ((isVisit[idx+1] == false) && (idx+1 <= 4) && (tmp1 != topni[idx+1][6])) {
        rotateTopni(idx+1, direction*(-1));
    }

    if ((isVisit[idx-1] == false) && (idx-1 >= 1) && (tmp2 != topni[idx-1][2])) {
        rotateTopni(idx-1, direction*(-1));
    }
}

int main() {
    for (int i = 1; i<=4; i++){
        string s;
        cin >> s;
        for (int j = 0; j<8; j++){
            topni[i][j] = s[j] - '0';
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i<k; i++){
        int a,b;
        cin >> a >> b;
        rotateVec.push_back(make_pair(a,b));
    }

    for (int i = 0; i<k; i++){
        memset(isVisit, false, sizeof(isVisit));
        rotateTopni(rotateVec[i].first, rotateVec[i].second);
    }

    int res = topni[1][0] + topni[2][0]*2 + topni[3][0]*4 + topni[4][0]*8;
    cout << res << endl;

    return 0;
}

