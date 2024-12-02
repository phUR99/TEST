#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int board[25][25];
int n, m;
bool visited[25][25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int i, int j)
{
    int cnt = 0;
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    bool NOT = false;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        cnt++;
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 0)
            {
                NOT = true;
                continue;
            }
            if (board[nx][ny] == 1 || visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (NOT)
        cnt = 0;
    return cnt;
}
int solve()
{
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 2 || visited[i][j])
                continue;
            ret += bfs(i, j);
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
    int ret = 0;
    for (int i = 0; i < n * m; i++)
    {
        for (int j = i + 1; j < n * m; j++)
        {
            int px = i / m;
            int py = i % m;
            int qx = j / m;
            int qy = j % m;
            if (board[px][py] == 0 && board[qx][qy] == 0)
            {
                board[px][py] = 1;
                board[qx][qy] = 1;
                ret = max(ret, solve());
                board[px][py] = 0;
                board[qx][qy] = 0;
            }
        }
    }
    cout << ret;
    return 0;
}