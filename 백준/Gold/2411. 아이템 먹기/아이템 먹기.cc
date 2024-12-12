#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, a, b;
int board[105][105];
int cache[105][105][105];
int solve(int x, int y, int num)
{
    if (x == n && y == m)
        return num == a;
    int &ret = cache[x][y][num];
    if (ret != -1)
        return ret;
    ret = 0;
    if (x + 1 <= n && board[x + 1][y] != 2)
        if (board[x + 1][y] == 1)
            ret += solve(x + 1, y, num + 1);
        else
            ret += solve(x + 1, y, num);
    if (y + 1 <= m && board[x][y + 1] != 2)
        if (board[x][y + 1] == 1)
            ret += solve(x, y + 1, num + 1);
        else
            ret += solve(x, y + 1, num);
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    while (b--)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }
    int ret;
    if (board[1][1] == 1)
        ret = solve(1, 1, 1);
    else
        ret = solve(1, 1, 0);
    cout << ret;
    return 0;
}