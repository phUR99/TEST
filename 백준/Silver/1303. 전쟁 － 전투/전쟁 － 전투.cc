#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[105][105];
bool visited[105][105];
int bfs(int x, int y)
{
    visited[x][y] = true;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    char c = board[x][y];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty())
    {
        auto here = q.front();
        q.pop();
        int cx = here.first;
        int cy = here.second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] != c || visited[nx][ny])
                continue;
            cnt++;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return cnt * cnt;
}

int main()
{
    fastio;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int W = 0, B = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                if (board[i][j] == 'W')
                    W += bfs(i, j);
                else
                    B += bfs(i, j);
            }
        }
    }
    cout << W << ' ' << B;
    return 0;
}