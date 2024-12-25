#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[10005][705];
bool visited[10005][705];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
int dfs(int x, int y)
{
    if (y == m)
        return 1;
    int ret = 0;
    // cout << x << ' ' << y << '\n';
    visited[x][y] = 1;
    for (int dir = 0; dir < 3; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny > m)
            continue;
        if (visited[nx][ny] || board[nx][ny] == 'x')
            continue;
        if (dfs(nx, ny))
        {
            return 1;
        }
    }
    // visited[x][y] = 0;
    return 0;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += dfs(i, 0);
    }

    cout << ret;
    return 0;
}