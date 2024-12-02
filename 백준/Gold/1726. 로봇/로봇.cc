#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int board[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(vector<int> st, vector<int> ed)
{
    int dist[105][105][4];
    memset(dist, -1, sizeof(dist));
    queue<vector<int>> q;
    q.push(st);
    dist[st[0]][st[1]][st[2]] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur[0];
        int y = cur[1];
        int d = cur[2];
        for (int i = 1; i <= 3; i++)
        {
            int nx = x + i * dx[d];
            int ny = y + i * dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                break;
            if (board[nx][ny])
                break;
            if (dist[nx][ny][d] != -1)
                continue;
            dist[nx][ny][d] = dist[x][y][d] + 1;
            q.push({nx, ny, d});
        }

        for (int dir = 0; dir < 4; dir++)
        {
            if (d == dir)
                continue;
            int ndx = dx[d] + dx[dir];
            int ndy = dy[d] + dy[dir];
            if (ndx == 0 && ndy == 0)
                continue;
            if (dist[x][y][dir] != -1)
                continue;
            dist[x][y][dir] = dist[x][y][d] + 1;
            q.push({x, y, dir});
        }
    }

    return dist[ed[0]][ed[1]][ed[2]];
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
    vector<int> st(3), ed(3);
    for (auto &i : st)
    {
        cin >> i;
        i--;
    }
    for (auto &i : ed)
    {
        cin >> i;
        i--;
    }

    int ret = bfs(st, ed);
    cout << ret;
    return 0;
}