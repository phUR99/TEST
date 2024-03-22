#include <bits/stdc++.h>
using namespace std;
/*
1. 동시에 확산되는 먼지 -> bfs로 구현
2. 환풍기의 움직임을 구현하는 것이 문제 -> 환풍기의 움직임을 만드는 배열을 구현
이후 배열에 체크된 원소들을 움직이게 만들자
0 우 1 하 2 좌 3 상
bfs 1회 실행시 NM * (4N+2m) * T = 50 * 50 * 300 * 1000
3. 거꾸로 하기 + 노가다
*/
int dx[] ={0, 1, 0, -1};
int dy[] ={1, 0, -1, 0};
int board[55][55];
int flow[55][55];
int r, c, t;

struct node{
    int x, y;
};
vector<node> pos;

void bfs(){
    queue<node> q;
    int newboard[55][55];
    memset(newboard, 0, sizeof(newboard));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <c ; j++){
            if(board[i][j] >= 5) q.push({i, j});
        }
    }
    while (!q.empty())
    {
        node cur = q.front(); q.pop();
        int dv = board[cur.x][cur.y]/5;
        for (int dir = 0; dir < 4; dir++)
        {            
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx <0 || nx >= r || ny <0 || ny >= c || board[nx][ny] == -1) continue;
            newboard[cur.x][cur.y] -= dv;
            newboard[nx][ny] += dv;
        }
        
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <c ; j++){
            if(board[i][j] != -1) board[i][j] += newboard[i][j];
        }
    }

    int ux = pos[0].x;
    int uy = pos[0].y;
    int bx = pos[1].x;
    int by = pos[1].y;
    board[ux-1][uy] =0;
    board[bx+1][by] =0;

    for (int x = ux-1; x >0; x--)
    {
        swap(board[x-1][uy],board[x][uy]);
    }
    for (int y = uy; y < c-1; y++)
    {
        swap(board[0][y+1], board[0][y]);
    }
    for (int x = 0; x < ux; x++)
    {
        swap(board[x+1][c-1], board[x][c-1]);
    }
    for (int y = c-1; y > uy+1; y--)
    {
        swap(board[ux][y-1], board[ux][y]);
    }
    

    for (int x = bx+1; x < r-1; x++)
    {
        swap(board[x+1][by], board[x][by]);
    }
    for (int y = by; y < c-1; y++)
    {
        swap(board[r-1][y+1], board[r-1][y]);
    }
    for (int x = r-1; x > bx; x--)
    {
        swap(board[x-1][c-1], board[x][c-1]);
    }
    for (int y = c-1; y > uy+1; y--)
    {
        swap(board[bx][y-1], board[bx][y]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <c ; j++){
            cin >> board[i][j];
            if(board[i][j] == -1) pos.push_back({i, j});
        }
    }
    while (t--)
    {
        bfs();
    }

    int ans =0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <c ; j++){
            if(board[i][j] > 0) ans += board[i][j];
        }
    }
    cout << ans;
    


    return 0;
}
