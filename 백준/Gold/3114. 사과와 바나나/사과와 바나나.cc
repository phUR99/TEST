#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int asum[1505][1505], bsum[1505][1505];
string board[1505][1505];
int n, m;
int cache[1505][1505];
int solve(int x, int y)
{
    if (x == n - 1 && y == m - 1)
        return asum[n - 1][m - 1] - (board[n - 1][m - 1].front() == 'A' ? stoi(board[n - 1][m - 1].substr(1)) : 0);
    int &ret = cache[x][y];
    if (ret != -1)
        return ret;
    int v = stoi(board[x][y].substr(1));
    ret = 0;
    if (x < n - 1)
        ret = max(ret, solve(x + 1, y) + asum[x][y] + bsum[x][y] - v);
    if (y < m - 1)
        ret = max(ret, solve(x, y + 1) - (board[x][y].front() == 'A' ? v : 0));
    if (x < n - 1 && y < m - 1)
        ret = max(ret, solve(x + 1, y + 1) + asum[x][y] + bsum[x][y] - v);
    return ret;
}
int main()
{
    fastio;
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int v = stoi(board[i][j].substr(1));
            if (board[i][j][0] == 'A')
                asum[i][j] = (j == 0) ? v : asum[i][j - 1] + v;
            else
                asum[i][j] = (j == 0) ? 0 : asum[i][j - 1] + 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int v = stoi(board[i][j].substr(1));
            if (board[i][j][0] == 'B')
                bsum[i][j] = (j == m - 1) ? v : bsum[i][j + 1] + v;
            else
                bsum[i][j] = (j == m - 1) ? 0 : bsum[i][j + 1] + 0;
        }
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}