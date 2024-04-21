#include <bits/stdc++.h>
using namespace std;
/*
1. 제초제 뿌리는 조건을 잘못잡음
2. 최소값 조건을 잘못 잡음. 무조건 min max 둘 중에 하나로 잡고 업데이트 하는 방식으로
*/


int n, m, k, c;
int board[25][25], tmp_board[25][25], state[25][25];
bool inrange(int x, int y){
    return x >= 0 && x <n && y >= 0 && y < n;
}
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int di_dx[] = {-1, -1, 1, 1};
const int di_dy[] = { -1, 1, -1, 1};
int ans = 0;

void printboard(){
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j <n; j++){                
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}
void copy(){
    for (int i = 0; i < n; i++)
    {
        for (int j =0; j <n; j++){                
            int &cur = tmp_board[i][j];
            board[i][j] += cur;
            cur = 0;
        }
    }
}
int weeding(int x, int y){        
    int ret = board[x][y];    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + di_dx[i];
        int ny = y + di_dy[i];
        int trial = k;
        while (inrange(nx, ny) && board[nx][ny] > 0 && trial-- && state[nx][ny] == 0)
        {
            ret += board[nx][ny];
            nx += di_dx[i];
            ny += di_dy[i];
        }        
    }    
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    while (m--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j =0; j <n; j++){  
                if(state[i][j] > 0) state[i][j]--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j =0; j <n; j++){  
                if(board[i][j] == -1 || board[i][j] == 0) continue;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(!inrange(nx, ny) || board[nx][ny] == 0 || board[nx][ny] == -1 || state[nx][ny]) continue;
                    int &cur = tmp_board[i][j];
                    cur++;
                    
                }                
            }
        }
        copy();
        pair<int, int> arr[4];
        for (int i = 0; i < n; i++)
        {
            for (int j =0; j <n; j++){                
                if(board[i][j] == -1 || board[i][j] == 0 || state[i][j] != 0) continue;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(!inrange(nx, ny) || board[nx][ny] != 0 || state[nx][ny] != 0) continue;
                    arr[cnt] = {nx, ny};
                    cnt++;
                }
                for (int idx = 0; idx < cnt; idx++){
                    int &cur = tmp_board[arr[idx].first][arr[idx].second];
                    cur += board[i][j] / cnt;
                }            
            }            
        }
        copy();
        int target = -987654321, x = -1, y = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j =0; j <n; j++){                
                if(board[i][j] == -1 || board[i][j] == 0 || state[i][j] != 0) continue;
                int cur = weeding(i, j);
                if(target  < cur){
                    target = cur;
                    x = i;
                    y = j;
                }
                else if (target == cur){
                    if (i < x){
                        x = i;
                        y = j;                        
                    }
                    else if (x == i && j < y){
                        y = j;
                    }
                }
            }            
        }
        ans += board[x][y];
        board[x][y] = 0;    
        state[x][y] = c + 1;    
        for (int i = 0; i < 4; i++)
        {
            int nx = x + di_dx[i];
            int ny = y + di_dy[i];
            int trial = k;
            while (inrange(nx, ny) && board[nx][ny] >= 0 && trial--) 
            {
                int cur = board[nx][ny];
                ans += board[nx][ny];
                board[nx][ny] = 0;
                state[nx][ny] = c + 1;  
                if(cur == 0)  break;            
                nx += di_dx[i];
                ny += di_dy[i];
                
            }        
        }
        
    }
    cout << ans;  


    return 0;
}