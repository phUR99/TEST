#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int board[105][105];
bool visited[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m, k;

int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    int ret = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] != 1 || visited[i][j])
                continue;
            int cnt = 0;
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty())
            {
                auto cur = q.front();
                int x = cur.first;
                int y = cur.second;
                cnt++;
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 1 || nx > n || ny < 1 || ny > m)
                        continue;
                    if (board[nx][ny] != 1 || visited[nx][ny])
                        continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ret = max(cnt, ret);
        }
    }
    cout << ret << '\n';
    return 0;
}