#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[605][605];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool visited[605][605];

int bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    int ret = 0;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        if (board[x][y] == 'P')
            ret++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 'X' || visited[nx][ny])
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'I')
            {
                sx = i;
                sy = j;
            }
        }
    }
    int ret = bfs(sx, sy);
    if (ret == 0)
        cout << "TT";
    else
        cout << ret;
    return 0;
}