#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
char board[55][55];
int cache[55][55][1 << 6];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
void findXY(int &x, int &y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '0')
            {
                x = i;
                y = j;
                return;
            }
        }
    }
}
void bfs()
{
    queue<vector<int>> q;
    int x = 0, y = 0;
    findXY(x, y);
    q.push({x, y, 0});
    cache[x][y][0] = 0;
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int curX = current[0];
        int curY = current[1];
        int curS = current[2];
        // cout << curX << ' ' << curY << ' ' << curS << '\n';
        if (board[curX][curY] == '1')
            continue;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '#')
                continue;
            if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
            {
                int shift = board[nx][ny] - 'A';
                if (((1 << shift) & curS))
                {
                    if (cache[nx][ny][curS] != -1)
                        continue;
                    cache[nx][ny][curS] = cache[curX][curY][curS] + 1;
                    q.push({nx, ny, curS});
                }
            }
            else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z')
            {
                int shift = board[nx][ny] - 'a';
                int nxtS = curS | (1 << shift);
                if (cache[nx][ny][nxtS] != -1)
                    continue;
                cache[nx][ny][nxtS] = cache[curX][curY][curS] + 1;
                q.push({nx, ny, nxtS});
            }
            else
            {
                if (cache[nx][ny][curS] != -1)
                    continue;
                cache[nx][ny][curS] = cache[curX][curY][curS] + 1;
                q.push({nx, ny, curS});
            }
        }
    }
    int ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '1')
            {
                for (int s = 0; s < (1 << 6); s++)
                {
                    if (cache[i][j][s] == -1)
                        continue;
                    ret = min(ret, cache[i][j][s]);
                }
            }
        }
    }
    cout << (ret == 987654321 ? -1 : ret) << '\n';
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    bfs();

    return 0;
}