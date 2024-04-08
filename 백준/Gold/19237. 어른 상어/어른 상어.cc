#include <bits/stdc++.h>
using namespace std;
struct smellinfo
{
    int num, cnt;
    void clear(){
        num = 0;
        cnt = 0;
    }
};
struct shark
{
    int dir;
    vector<int> pdir[5];
    void clear(){        
        dir = 0;
    }
};
shark info[405];
int board[25][25];
int tmp_board[25][25];

smellinfo smell[25][25];


int n, m, k;
const int MX = 987654321;
const int dx[] = {MX, -1, 1, 0, 0};
const int dy[] = {MX,  0, 0,-1, 1};
int cnt;


bool inrange(int x, int y){
    return x > 0 && x <=n &&  y >0 && y <= n;
}

void move(){
    for (int x = 1; x<= n; x++){
        for (int y =1; y <= n; y++){
            if(board[x][y]){
                int nx = x;
                int ny = y;
                int moveX = x;
                int moveY = y;
                bool flag = false;
                int num = board[x][y];
                const vector<int> &cur = info[num].pdir[info[num].dir];
                for (int dir = 0; dir < 4; dir++){                                        
                    nx = x + dx[cur[dir]];
                    ny = y + dy[cur[dir]];
                    if(!inrange(nx, ny)) continue;
                    if(smell[nx][ny].num == 0){
                        moveX = nx;
                        moveY = ny;
                        info[num].dir = cur[dir];
                        break;
                    }
                    else if(flag == false && smell[nx][ny].num == num){
                        moveX = nx;
                        moveY = ny;
                        flag = true;
                        info[num].dir = cur[dir];
                    }
                    else{
                        continue;
                    }                    
                }
                if(tmp_board[moveX][moveY]){
                    tmp_board[moveX][moveY] = min(tmp_board[moveX][moveY], num);
                    cnt--;
                }
                else{
                    tmp_board[moveX][moveY] = num;
                }
            }
        }
    }
    return;
}
void copy(){

    for (int i =1; i <=n; i++){
        for (int j =1; j <=n; j++){
            board[i][j] = tmp_board[i][j];
        }
    }
    return;
}
void init(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {
            if(smell[i][j].cnt > 1) smell[i][j].cnt--;                              
            else if (smell[i][j].cnt == 1) smell[i][j].clear();
        }        
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {
            if(board[i][j]){
                smell[i][j].cnt = k;
                smell[i][j].num = board[i][j];
            }
        }        
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cnt = m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            if(board[i][j]){
                smell[i][j].num = board[i][j];
                smell[i][j].cnt = k;
            }
        }
        
    }
    for (int k = 1; k <= m; k++)
    {
        cin >> info[k].dir;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j =1; j <= 4; j++)
        {
            for(int k = 0; k <4; k++){
                int tmp;
                cin >> tmp;
                info[i].pdir[j].push_back(tmp);
            }
        }
    }    
    for (int t = 1; t <= 1000; t++)
    {
        memset(tmp_board, 0, sizeof(tmp_board));
        move();        
        if(cnt == 1){
            cout << t;
            return 0;
        }
        copy();
        init();       
    }
    cout << -1;        
    return 0;
}