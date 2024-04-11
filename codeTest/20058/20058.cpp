#include <bits/stdc++.h>
using namespace std;
#define MXSIZE 64

int tmp_board[MXSIZE][MXSIZE];
int board[MXSIZE][MXSIZE];
bool visited[MXSIZE][MXSIZE];
int n, q, L, SIZE;
const int dx[] ={-1, 1, 0 ,0};
const int dy[] ={0, 0, -1, 1};

bool outRange(int x, int y){
    return x < 0 || x >= SIZE ||  y < 0 || y >= SIZE;
}

void rotate(int l, int x, int y){    
    if(l == L){                
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++){                
                tmp_board[j][l-1-i] = board[x+i][y+j];
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++){
                board[i+x][j+y] = tmp_board[i][j];
            }
        }        
        return;
    }    
    rotate(l/2, x,     y);
    rotate(l/2, x,     y + l/2);
    rotate(l/2, x+ l/2, y);
    rotate(l/2, x+ l/2, y + l/2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    SIZE = 1 << n;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j =0; j < SIZE; j++){
            cin >> board[i][j];
        }
    }
    while (q--)
    {        
        cin >> L;
        L = 1 << L;        
        rotate(SIZE, 0, 0);
        memset(tmp_board, 0, sizeof(tmp_board));
        for (int i = 0; i < SIZE; i++)
        {            
            for (int j =0; j < SIZE; j++){                
                if(board[i][j] == 0) continue;
                int cnt = 0;
                for(int dir =0; dir <4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(outRange(nx, ny)||board[nx][ny] == 0) continue;
                    cnt++;
                }
                if (cnt < 3) tmp_board[i][j] = -1;
            }
        }
        for (int i = 0; i < SIZE; i++)
        {            
            for (int j =0; j < SIZE; j++){
                board[i][j] += tmp_board[i][j];
            }
        }
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < SIZE; i++)
    {            
        for (int j =0; j < SIZE; j++){
            ans += board[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < SIZE; i++)
    {            
        for (int j =0; j < SIZE; j++){
            if(board[i][j] ==0 || visited[i][j]) continue;
            visited[i][j] = true;
            int tmp = 1;
            q.push({i, j});
            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4 ; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(outRange(nx, ny) || visited[nx][ny]) continue;
                    if(board[nx][ny]==0) continue;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    tmp++;
                }
            }
            cnt = max(tmp, cnt);
        }
    }
    cout << ans << '\n' << cnt;
    return 0;    
}