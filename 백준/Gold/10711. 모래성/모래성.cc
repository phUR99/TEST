#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int board[1005][1005];
int zeroCnt[1005][1005];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m;

bool oob(int x, int y)
{
    return x < 0 || x >= n || y < 0 || y >= m;
}
bool solve(queue<pair<int, int>> &q)
{
    if (q.empty())
        return false;
    queue<pair<int, int>> nxtQ;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (oob(nx, ny))
                continue;
            zeroCnt[nx][ny]++;
            if (zeroCnt[nx][ny] == board[nx][ny])
                nxtQ.push({nx, ny});
        }
    }
    q = nxtQ;
    return true;
}
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (isdigit(c))
                board[i][j] = c - '0';
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!board[i][j])
                continue;
            int cnt = 0;
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (oob(nx, ny))
                    continue;
                if (board[nx][ny] == 0)
                    cnt++;
            }
            zeroCnt[i][j] = cnt;
            if (cnt >= board[i][j])
                q.push({i, j});
        }
    }
    int ret = 0;
    while (solve(q))
    {
        ret++;
        /*
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << max(0, board[i][j] - zeroCnt[i][j]);
            }
            cout << '\n';
        }
        cout << '\n';
        */
    }
    cout << ret;
    return 0;
}