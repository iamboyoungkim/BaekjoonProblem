#include <iostream>
#include <vector>
#include <ctype.h>
#include <queue>

using namespace std;
struct point{
    int y;
    int x;
    int IsKey;
    int cnt;
};


int main()
{
    int N,M;
    vector< vector<char> > map(N, vector<char>(M, '-1'));
    queue< point > queue;
    int dir[4][4] = {{0,-1,0,1},{1,0,-1,0}};
    cin >> N;
    cin >> M;
    point cur_point;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if (map[i][j] == '0')
                cur_point = {i, j ,0 , 0};
        }
    }
    queue.push(cur_point);
    
    int cur_IsKey, next_IsKey, next_y, next_x,next_cnt ;
    char next_char;
    int cnt = 0;
    while(!queue.empty() || cnt <100){
        cur_point = queue.front();
        queue.pop();
        cur_IsKey = cur_point.IsKey;
        
        for(int i=0; i<4; i++){
            next_y = cur_point.y + dir[i][0];
            next_x = cur_point.x + dir[i][1];
            if ( next_y <0 || next_x <0 ||next_y >=N ||next_x >= M)
                continue;
            next_IsKey = cur_IsKey;
            next_cnt = cur_point.cnt +1;
            cout << "next :  "<<next_y << next_x << endl;
            next_char = map[next_y][next_x];
            if (next_char =='#')
                continue;
            else if (isdigit(next_char) && next_char=='1')
                return next_cnt ;
            else if(isalpha(next_char)){
                if(islower(next_char)){
                    cur_IsKey  |= (1 << int(next_char)-97);
                    queue.push({next_y, next_x, cur_IsKey,next_cnt});
                }else {
                    if(cur_IsKey & (1 << int(next_char)-65)){
                        queue.push({next_y, next_x, cur_IsKey,next_cnt});
                    }
                }
            }else{
                queue.push({next_y, next_x, cur_IsKey ,next_cnt});
            }
            
        }
        cnt++;
    }
    
    return -1;
}