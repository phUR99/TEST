#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, t;
int board[105][105][3];
int dist[105][105][3];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0][0] = 0;
    priority_queue<vector<int>> pq;
    pq.push({0, 0, 0, 0});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int cost = -cur[0];
        int time = cur[1];
        int x = cur[2];
        int y = cur[3];
        if (dist[x][y][time] < cost)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            int nt = (time + 1) % 3;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (cost + t + board[nx][ny][nt] < dist[nx][ny][nt])
            {
                dist[nx][ny][nt] = cost + t + board[nx][ny][nt];
                pq.push({-dist[nx][ny][nt], nt, nx, ny});
            }
        }
    }
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < 3; i++)
    {
        ret = min(ret, dist[n - 1][n - 1][i]);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j][0];
        }
    }
    int ret = dijkstra();
    cout << ret << '\n';

    return 0;
}