#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int board[105][105];
bool visited[105][105];
int bfs(int h)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
    int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            if (board[i][j] == h)
            {
                q.push({i, j});
                visited[i][j] = true;
                cnt++;
                while (!q.empty())
                {
                    auto here = q.front();
                    int x = here.first;
                    int y = here.second;
                    q.pop();
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (visited[nx][ny])
                            continue;
                        if (board[x][y] - board[nx][ny] >= 0)
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    fastio;
    cin >> n >> m;
    int h = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            h = max(h, board[i][j]);
        }
    }
    int ret = 0;
    for (int i = h; i >= 0; i--)
    {
        ret += bfs(i);
    }
    cout << ret;
    return 0;
}