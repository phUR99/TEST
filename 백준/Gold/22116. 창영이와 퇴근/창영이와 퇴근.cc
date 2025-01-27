#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int board[1005][1005];
bool visited[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool bfs(int v)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        auto here = q.front();
        q.pop();
        int x = here.first;
        int y = here.second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visited[nx][ny] || abs(board[nx][ny] - board[x][y]) > v)
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return visited[n - 1][n - 1];
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    int l = 0;
    int r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bfs(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}