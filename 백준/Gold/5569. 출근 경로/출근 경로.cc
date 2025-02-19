#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[105][105][2][200];
int w, h;
int solve(int x, int y, int dir, int c)
{
    if (x == w && y == h)
        return 1;
    int &ret = cache[x][y][dir][c];
    if (ret != -1)
        return ret;
    ret = 0;
    if (dir == 0 && x < w)
        ret += solve(x + 1, y, 0, c + 1);
    if (dir == 1 && x < w && c > 1)
        ret += solve(x + 1, y, 0, 1);
    if (dir == 1 && y < h)
        ret += solve(x, y + 1, 1, c + 1);
    if (dir == 0 && y < h && c > 1)
        ret += solve(x, y + 1, 1, 1);
    ret %= 100000;
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> w >> h;
    int ret = solve(2, 1, 0, 2) + solve(1, 2, 1, 2);
    cout << ret % 100000;
    return 0;
}