#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[10 * 10][1 << 12];
char board[12][12];
int n, m;
int solve(int pos, int state)
{
    if (pos >= n * m)
        return 0;
    int &ret = cache[pos][state];
    if (ret != -1)
        return ret;
    ret = solve(pos + 1, state >> 1);
    if (!(state & 1) && board[pos / m][pos % m] == '.')
    {
        int nxtState = state;
        if (pos % m != 0)
            nxtState |= 1 << (m - 1);
        if (pos % m != m - 1)
        {
            nxtState |= 1 << (m + 1);
            nxtState |= 1 << 1;
        }

        ret = max(ret, 1 + solve(pos + 1, nxtState >> 1));
    }
    return ret;
}
void solve()
{
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ret = solve(0, 0);
    cout << ret << '\n';
}
int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}