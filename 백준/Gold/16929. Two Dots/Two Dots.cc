#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char board[55][55];
bool visited[55][55];
int n, m;
bool OOB(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
bool dfs(pair<int, int> here, pair<int, int> prev, pair<int, int> start)
{
    int x = here.first;
    int y = here.second;
    char c = board[x][y];
    visited[x][y] = true;
    bool ret = false;
    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        pair<int, int> there = {nx, ny};
        if (OOB(nx, ny))
            continue;
        if (there == prev)
            continue;
        if (there == start)
            return true;
        if (!visited[nx][ny] && board[nx][ny] == c)
        {
            ret |= dfs(there, here, start);
        }
    }
    return ret;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(visited, 0, sizeof(visited));
            if (dfs({i, j}, {-1, -1}, {i, j}))
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}