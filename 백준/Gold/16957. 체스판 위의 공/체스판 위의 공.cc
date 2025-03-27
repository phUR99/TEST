#include <iostream>
#include <string.h>

using namespace std;
int r, c;
int board[505][505];
int cnt[505][505];
int parent[505][505];
bool visited[505][505];
bool oob(int x, int y){
    return x < 0 || x >=r || y <0 || y >= c;
}
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};

int find(int u){
    int row = u / c;
    int col = u % c;
    if (u == parent[row][col]) return u;
    return u = find(parent[row][col]);
    
}
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (board[u/c][u%c] > board[v/c][v%c]){
        swap(u, v);
    }
    parent[v/c][v%c] = u;
    cnt[u/c][u%c] += cnt[v/c][v%c];
    cnt[v/c][v%c] = 0;
}

void dfs(int i, int j){

    if (visited[i][j])
        return;
    visited[i][j] = 1;
    
    int idx = -1;
    int now = board[i][j];
    for (int dir = 0; dir < 8; dir++)
    {
        int nx = dx[dir] + i;
        int ny = dy[dir] + j;
        if (oob(nx, ny))
            continue;
        if (now > board[nx][ny])
        {
            now = board[nx][ny];
            idx = dir;
        }
        
    }
    if (idx == -1)
        return;
    
    int nx = dx[idx] + i;
    int ny = dy[idx] + j;
    merge(parent[i][j], parent[nx][ny]);
    dfs(nx, ny);
}

int main(){
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            cnt[i][j] = 1;
            parent[i][j] = i * c + j;
        }
        
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!visited[i][j])
                dfs(i, j);
    }
        
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    }
    

    

    return 0;

}