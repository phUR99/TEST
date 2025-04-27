#include <bits/stdc++.h>
using namespace std;

int cache[1005][1005][3];
int board[1005][1005];
int n;

int solve(int x, int y, int prev)
{
    if (x == n - 1 && y == n - 1)
        return (board[x][y] == prev);
    int &ret = cache[x][y][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    if (x < n - 1)
    {
        if (board[x][y] == prev)
            ret = max(ret, 1 + solve(x + 1, y, (prev + 1) % 3));
        ret = max(ret, solve(x + 1, y, prev));
    }
    if (y < n - 1)
    {
        if (board[x][y] == prev)
            ret = max(ret, 1 + solve(x, y + 1, (prev + 1) % 3));
        ret = max(ret, solve(x, y + 1, prev));
    }
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0, 0);
    cout << ret;
    return 0;
}