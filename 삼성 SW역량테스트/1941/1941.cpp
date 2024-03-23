#include <bits/stdc++.h>
using namespace std;
char board[5][5];
int a[7];
int ans =0;
int dx[] ={-1, 0, 1, 0};
int dy[] ={0, -1, 0, 1};


int bfs(){
    int ret =0;
    queue<pair<int, int>> q;
    bool isUsed[5][5];
    bool isP[5][5];
    memset(isP, false, sizeof(isP));
    memset(isUsed, false, sizeof(isUsed));
    int S=0, adj=0;

    for (int i = 0; i < 7; i++)
    {
        
        isP[a[i]/5][a[i]%5] = true;
        if(q.empty()){
            q.push({a[i] /5, a[i] %5});
            isUsed[a[i]/5][a[i]%5] = true;
        }
    }
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        adj++;
        if(board[cur.first][cur.second] == 'S') S++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx <0 || nx >= 5 || ny <0 || ny >= 5 || isUsed[nx][ny] || !isP[nx][ny]) continue;
            q.push({nx, ny});
            isUsed[nx][ny] = true;
        }
        
    }
    return ret = (adj >=7 && S >=4) ? 1 : 0;


}


void recursion(int cnt, int idx){
    if(cnt == 7){
        ans += bfs();
        return;
    }
    for (int i = idx; i < 25; i++)
    {        
        a[cnt] = i;
        recursion(cnt+1, i+1);
    }
    
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }        
    }
    recursion(0, 0);
    cout << ans;
    return 0;
}