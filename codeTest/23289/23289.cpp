#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[24][24];
int state[24][24];
int tmp_state[24][24];
bool wall[24][24][2];
bool inrange(int x, int y){
    return x >=1 && x <= n && y >=1 && y <= n;
}

void wind(int x, int y, int dir, int cnt){
    if(cnt == 0) return;
    // 오
    //0 -> 위
    //1 -> 왼
    if(dir == 4){        
        if(inrange(x-1, y+1) && wall[x][y][0] == false && wall[x-1][y+1][1] == false) {
            if(!tmp_state[x-1][y+1]){
                tmp_state[x-1][y+1] = cnt;
                wind(x-1, y+1, dir, cnt -1);
            }                      
        }
        if(inrange(x, y+1) && wall[x][y+1][1] == false) {
            if(!tmp_state[x][y+1]){
                tmp_state[x][y+1] = cnt;
                wind(x, y+1, dir, cnt -1);
            }                       
        }
        if(inrange(x+1, y+1) && wall[x+1][y][0] == false && wall[x+1][y+1][1] == false) {
            if(!tmp_state[x+1][y+1]){
                tmp_state[x+1][y+1] = cnt;
                wind(x+1, y+1, dir, cnt -1);
            }                       
        }            
    }
    // 왼 
    //0 -> 위
    //1 -> 왼
    else if (dir == 2){
        if(inrange(x-1, y-1) && wall[x][y][0] == false && wall[x-1][y][1] == false) {
            if(!tmp_state[x-1][y-1]){
                tmp_state[x-1][y-1] = cnt;
                wind(x-1, y-1, dir, cnt -1);
            }                        
        }
        if(inrange(x, y-1) && wall[x][y][1] == false) {
            if(!tmp_state[x][y-1]){
                tmp_state[x][y-1] = cnt;
                wind(x, y-1, dir, cnt -1);
            }                   
        }
        if(inrange(x+1, y-1) && wall[x+1][y][0] == false && wall[x+1][y][1] == false) {
            if(!tmp_state[x+1][y-1]){
                tmp_state[x+1][y-1] = cnt;
                wind(x+1, y-1, dir, cnt -1);
            }                   
        }            
    }
    // 위
    //0 -> 위
    //1 -> 왼
    else if (dir == 3){
        if(inrange(x-1, y+1) && wall[x][y+1][1] == false && wall[x][y+1][0] == false) {
            if(!tmp_state[x-1][y+1]){
                tmp_state[x-1][y+1] = cnt;
                wind(x-1, y+1, dir, cnt -1);
            }                        
        }
        if(inrange(x-1, y) && wall[x][y][0] == false) {
            if(!tmp_state[x-1][y]){
                tmp_state[x-1][y] = cnt;
                wind(x-1, y, dir, cnt -1);
            }            
        }
        if(inrange(x-1, y-1) && wall[x][y][1] == false && wall[x][y-1][0] == false) {
            if(!tmp_state[x-1][y-1]){
                tmp_state[x-1][y-1] = cnt;
                wind(x-1, y-1, dir, cnt -1);
            }            
        }            
    }
    //아 0 -> 위 1 -> 왼
    else{
        if(inrange(x+1, y+1) && wall[x][y+1][1] == false && wall[x+1][y+1][0] == false) {
            if(tmp_state[x+1][y+1] == 0){
                tmp_state[x+1][y+1] = cnt;
                wind(x+1, y+1, dir, cnt -1);
            }            
        }
        if(inrange(x+1, y) && wall[x+1][y][0] == false) {
            if(tmp_state[x+1][y] == 0){
                tmp_state[x+1][y] = cnt;
                wind(x+1, y, dir, cnt -1);
            }            
        }
        if(inrange(x+1, y-1) && wall[x][y][1] == false && wall[x+1][y-1][0] == false) {
            if(tmp_state[x+1][y-1] == 0){
                tmp_state[x+1][y-1] = cnt;
                wind(x+1, y-1, dir, cnt -1);
            }            
        }     
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j =1; j <= n; j++){
            cin >> board[i][j];
        }
    }
    while (m--)
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        wall[x][y][dir] = true;
    }
    bool isOkay;
    int cnt = 0;
    do
    {
        isOkay = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++){
                int cur = board[i][j];
                if(cur == 0 || cur == 1) continue;                
                int x, y;                
                if (cur == 4){
                    x = i;
                    y = j + 1;
                }
                else if (cur == 2){
                    x = i;
                    y = j - 1;                    
                }
                else if (cur == 3){
                    x = i - 1;
                    y = j;
                }
                else {
                    x = i + 1;
                    y = j;
                }
                tmp_state[x][y] = 5;
                wind(x, y, cur, 4);
                for (int i = 1; i <= n; i++)
                {
                    for (int j =1; j <= n; j++){
                        state[i][j] += tmp_state[i][j];
                        tmp_state[i][j] = 0;
                    }
                }                
            }
    
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++){
                int cur = state[i][j];
                if (cur == 0) continue;
                for (int k = 0; k < 4; k++)
                {                    
                    if (k == 0){
                        int nx = i;
                        int ny = j +1;
                        int nxt = state[nx][ny];
                        if(!inrange(nx, ny) || cur < nxt || wall[nx][ny][1]) continue;
                        int diff = (cur - nxt) / 4;
                        tmp_state[i][j] -= diff;
                        tmp_state[nx][ny] += diff;
                    }
                    else if (k == 1){
                        int nx = i + 1;
                        int ny = j;
                        int nxt = state[nx][ny];
                        if(!inrange(nx, ny) || cur < nxt || wall[nx][ny][0]) continue;
                        int diff = (cur - nxt) / 4;
                        tmp_state[i][j] -= diff;
                        tmp_state[nx][ny] += diff;
                    }
                    else if (k == 2){
                        int nx = i;
                        int ny = j - 1;
                        int nxt = state[nx][ny];
                        if(!inrange(nx, ny) || cur < nxt || wall[i][j][1]) continue;
                        int diff = (cur - nxt) / 4;
                        tmp_state[i][j] -= diff;
                        tmp_state[nx][ny] += diff;
                    }
                    else{
                        int nx = i - 1;
                        int ny = j;
                        int nxt = state[nx][ny];
                        if(!inrange(nx, ny) || cur < nxt || wall[i][j][0]) continue;
                        int diff = (cur - nxt) / 4;
                        tmp_state[i][j] -= diff;
                        tmp_state[nx][ny] += diff;
                    }
                }
                
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++){
                state[i][j] += tmp_state[i][j];
                tmp_state[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++){
                if((i == 1 || i == n || j == 1 || j == n) && state[i][j] != 0) state[i][j]--;   
            }            
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++){
                if(board[i][j] == 1 && state[i][j] < k) {
                    isOkay = false;
                    break;
                }    
            }        
            if(!isOkay) break;
        }        
        cnt++;
    } while (cnt < 100 && isOkay == false);
    if(!isOkay) cout << -1;
    else cout << cnt;
    
    

    return 0;
}