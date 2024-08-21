#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int n, m, k;
char board[1005][1005];
int dist[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }
    memset(dist, -1, sizeof(dist));

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int nx = cur.first + dx[i] * j;
                int ny = cur.second + dy[i] * j;
                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    break;
                if (board[nx][ny] == '#')
                    break;

                if (dist[nx][ny] != -1 && dist[nx][ny] < dist[cur.first][cur.second] + 1)
                    break;
                if (dist[nx][ny] == dist[cur.first][cur.second] + 1)
                    continue;

                q.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }
    cout << dist[ex][ey];
    return 0;
}