#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, sx, sy, ex, ey;
int board[1005][1005];
int dist[1005][1005][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int bfs()
{
    queue<array<int, 3>> q;
    q.push({sx, sy, 0});
    dist[sx][sy][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int t = cur[2];
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int nt = t + board[nx][ny];
            if (nt >= 2 || dist[nx][ny][nt] != -1)
                continue;
            dist[nx][ny][nt] = dist[x][y][t] + 1;
            q.push({nx, ny, nt});
        }
    }
    if (dist[ex][ey][0] == -1 && dist[ex][ey][1] == -1)
        return -1;
    else if (dist[ex][ey][0] == -1)
        return dist[ex][ey][1];
    else if (dist[ex][ey][1] == -1)
        return dist[ex][ey][0];
    else
        return min(dist[ex][ey][1], dist[ex][ey][0]);
}

int main()
{
    fastio;
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> ex >> ey;
    sx--, sy--, ex--, ey--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = bfs();
    cout << ret;
    return 0;
}