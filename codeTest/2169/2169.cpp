#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[1005][1005][3];
int board[1005][1005];
bool visited[1005][1005];
int dx[] = {1, 0, 0}; 
int dy[] = {0, 1, -1};
const int NOT = -987654321;
/*
DP접근에서 한번 접근한 위치는 다시 접근하지 못한다는 것을 어떻게 구현하는 것이 문제였음
특히, dist 배열을 들어오는 방향에 따라서 다르게 선언해줘야 하는 것
ret을 0으로 초기화할 경우 문제가 생길 수 있다는 것
*/


int dp(int x, int y, int dir){
    if(x < 0 || x >= n || y < 0 || y >= m) return NOT;     
    if(visited[x][y]) return NOT;
    if(x==n-1 & y == m-1) return board[n-1][m-1];    
    int& ret = dist[x][y][dir];
    if(ret != -1) return ret;
    visited[x][y] = true;
    //ret = 0 으로 설정할 경우 board의 값이 0 이하로 나올 수 있기 때문에 오류가 생길 수 있음
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