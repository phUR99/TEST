#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
char board[12][12];
int cache[11 * 11][1 << 11];
int score[][6] = {
    {100, 70, 40, 0, 0, 0},
    {70, 50, 30, 0, 0, 0},
    {40, 30, 20, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}};

int returnScore(int p1, int p2)
{
    string str = string(1, board[p1 / n][p1 % n]) + string(1, board[p2 / n][p2 % n]);
    return score[str[0] - 'A'][str[1] - 'A'];
}

int solve(int p, int s)
{
    if (p == n * n && s == 0)
        return 0;
    if (p >= n * n && s != 0)
        return -987654321;
    int &ret = cache[p][s];
    if (ret != -1)
        return ret;
    ret = solve(p + 1, s >> 1);
    if (!(s & 1))
    {
        if (p % n != n - 1 && !(s & 2))
            ret = max(ret, returnScore(p, p + 1) + solve(p + 2, s >> 2));
        ret = max(ret, returnScore(p, p + n) + solve(p + 1, s >> 1 | 1 << (n - 1)));
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
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}