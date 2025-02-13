#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
char board[15][15];
int cache[14 * 14][1 << 14];
int score[][6] = {
    {10, 8, 7, 5, 0, 1},
    {8, 6, 4, 3, 0, 1},
    {7, 4, 3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0}};
int returnScore(int pos1, int pos2)
{
    int r1 = pos1 / m;
    int c1 = pos1 % m;
    int r2 = pos2 / m;
    int c2 = pos2 % m;
    return score[board[r1][c1] - 'A'][board[r2][c2] - 'A'];
}

int solve(int pos, int state)
{
    if (pos >= n * m)
        return 0;
    int &ret = cache[pos][state];
    if (ret != -1)
        return ret;
    ret = 0;
    ret = solve(pos + 1, state >> 1);
    if (!(state & 1))
    {
        if (pos + 1 < n * m && !(state & 2) && pos % m != m - 1)
        {
            int rPos = pos + 1;
            ret = max(ret, returnScore(pos, rPos) + solve(pos + 2, state >> 2));
        }
        if (pos + m < n * m && !(state & (1 << m)))
        {
            int dPos = pos + m;
            ret = max(ret, returnScore(pos, dPos) + solve(pos + 1, (state >> 1) | (1 << (m - 1))));
        }
    }
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
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}