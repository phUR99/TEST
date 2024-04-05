#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[1005][1005][3];
int board[1005][1005];
bool visited[1005][1005];
int dx[] = {1, 0, 0}; 
int dy[] = {0, 1, -1};
const int NOT = -987654321;

int dp(int x, int y, int dir){
    if(x < 0 || x >= n || y < 0 || y >= m) return NOT; 
    if(visited[x][y]) return NOT;
    if(x==n-1 & y == m-1) return board[n-1][m-1];
    int& ret = dist[x][y][dir];
    if(ret != -1) return ret;
    visited[x][y] = true;
    ret = NOT;
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret = max(ret, dp(nx, ny, i)+board[x][y]);
    }
    visited[x][y] = false;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }        
    }
    memset(dist, -1, sizeof(dist));
    cout<< dp(0, 0, 0);

    
    
    return 0;    
}