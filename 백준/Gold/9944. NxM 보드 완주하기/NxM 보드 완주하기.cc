#include <bits/stdc++.h>
using namespace std;
int n, m, ret, total;
char board[35][35];
bool visited[35][35];
bool oob(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}
int dx[] = {-1, 1, 0, 0, 9876};
int dy[] = {0, 0, -1, 1, 9876};
void dfs(int x, int y, int dir, int cnt, int sum){
    visited[x][y] = 1;
    if(sum == total){
        ret = min(ret, cnt);
        visited[x][y] = 0;
    }
    int nx = dx[dir] + x;
    int ny = dy[dir] + y;
    auto notEntry = [](int nx, int ny){return visited[nx][ny] || board[nx][ny] == '*';};
    if (oob(nx, ny) || notEntry(nx, ny)){
        for (int i = 0; i < 4; i++)
        {
            nx = dx[i] + x;
            ny = dy[i] + y;
            if (oob(nx, ny) || notEntry(nx, ny)) continue;
            dfs(nx, ny, i, cnt + 1, sum + 1);
        }
        
    }
    else    
        dfs(nx, ny, dir, cnt, sum + 1);
    visited[x][y] = 0;
}

void solve(int t){
    total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == '.')
                total++;
        }   
    }
    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] == '*') continue;
            memset(visited, 0, sizeof(visited));  
            dfs(i, j, 4, 0, 1);
        }
        
    }
    if(ret == 987654321) ret = -1; 
    cout << "Case " << t << ": " << ret << '\n';
    
}

int main(){ 
    int cnt = 0;
    while (cin >> n >> m)
    {
        solve(++cnt);
    }
    

    return 0;
}