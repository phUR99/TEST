#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int n, m, t;
int dist[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int board[105][105];

int main()
{
    fastio;

    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            dist[i][j] = 987654321;
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 1 || dist[nx][ny] != 987654321)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    int answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 2)
            {
                answer = dist[i][j] + n - 1 - i + m - 1 - j;
            }
        }
    }
    answer = min(answer, dist[n - 1][m - 1]);
    if (answer > t)
        cout
            << "Fail";
    else
        cout << answer;

    return 0;
}