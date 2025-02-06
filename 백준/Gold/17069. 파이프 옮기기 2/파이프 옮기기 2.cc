#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll cache[35][35][3];
int board[35][35];
int n;
auto oob = [](int x, int y) -> bool
{ return x < 0 || x >= n || y < 0 || y >= n; };
ll solve(int x, int y, int pos)
{
    if (x == n - 1 && y == n - 1)
        return 1;
    ll &ret = cache[x][y][pos];
    if (ret != -1)
        return ret;
    ret = 0;
    pair<int, int> right = {x, y + 1};
    pair<int, int> down = {x + 1, y};
    pair<int, int> diag = {x + 1, y + 1};
    bool r = !oob(right.first, right.second) && !board[right.first][right.second];
    bool d = !oob(down.first, down.second) && !board[down.first][down.second];
    bool di = r && d && !oob(diag.first, diag.second) && !board[diag.first][diag.second];
    if (r && pos != 1)
        ret += solve(right.first, right.second, 0);
    if (d && pos != 0)
        ret += solve(down.first, down.second, 1);
    if (di)
        ret += solve(diag.first, diag.second, 2);
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    ll ret = solve(0, 1, 0);
    cout << ret;

    return 0;
}