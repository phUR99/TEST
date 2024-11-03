#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int n, m, k;
char board[105][105];
int cache[105][105][85];
string str;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int solve(int idx, int x, int y)
{
    if (idx == str.size() - 1)
        if (board[x][y] == str[idx])
            return 1;
        else
            return 0;

    if (board[x][y] != str[idx])
        return 0;
    int &ret = cache[x][y][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        for (int i = 1; i <= k; i++)
        {
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                break;
            ret += solve(idx + 1, nx, ny);
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> str;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret += solve(0, i, j);
        }
    }
    cout << ret << '\n';
    return 0;
}