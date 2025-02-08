#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int board[1005][1005];
int cache[1005][1005][4];

int solve(int row, int col, int prev)
{
    if (row == n)
        return 0;
    int &ret = cache[row][col][prev];
    if (ret != -1)
        return ret;
    ret = 987654321;
    if (prev == 1 || !prev)
    {
        ret = min(ret, board[row][col] + solve(row + 1, col, 2));
        if (col != m - 1)
            ret = min(ret, board[row][col] + solve(row + 1, col + 1, 3));
    }
    if (prev == 2 || !prev)
    {
        if (col != 0)
            ret = min(ret, board[row][col] + solve(row + 1, col - 1, 1));
        if (col != m - 1)
            ret = min(ret, board[row][col] + solve(row + 1, col + 1, 3));
    }
    if (prev == 3 || !prev)
    {
        ret = min(ret, board[row][col] + solve(row + 1, col, 2));
        if (col != 0)
            ret = min(ret, board[row][col] + solve(row + 1, col - 1, 1));
    }
    return ret;
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
    int ret = 987654321;
    for (int i = 0; i < m; i++)
    {
        ret = min(ret, solve(0, i, 0));
    }
    cout << ret;
    return 0;
}