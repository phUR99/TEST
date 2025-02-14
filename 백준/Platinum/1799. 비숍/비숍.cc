#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int board[15][15];
bool diag1[30], diag2[30];
int nxtPos(int pos)
{
    if (pos % n == n - 1 && n % 2 == 0)
        return 1;
    if (pos % n == n - 2 && n % 2 == 0)
        return 3;
    return 2;
}

int solve(int pos)
{
    if (pos >= n * n)
        return 0;

    int ret = solve(pos + nxtPos(pos));
    int x = (pos) / n;
    int y = (pos) % n;
    int d1 = y - x + n - 1;
    int d2 = x + y;
    if (board[x][y] && !diag1[d1] && !diag2[d2])
    {
        diag1[d1] = diag2[d2] = 1;
        ret = max(ret, 1 + solve(pos + nxtPos(pos)));
        diag1[d1] = diag2[d2] = 0;
    }

    return ret;
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
    int ret = solve(0) + solve(1);
    cout << ret;
    return 0;
}