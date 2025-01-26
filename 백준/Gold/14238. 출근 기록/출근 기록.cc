#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cnt[3];
string str;
int cache[55][55][55][3][3];
int solve(int a, int b, int c, int prev1, int prev2)
{
    if (a + b + c == str.size())
        return cache[a][b][c][prev1][prev2] = 1;
    int &ret = cache[a][b][c][prev1][prev2];
    if (ret != -1)
        return ret;
    ret = 0;
    if (a < cnt[0])
        ret |= solve(a + 1, b, c, 0, prev1);
    if (b < cnt[1] && prev1 != 1)
        ret |= solve(a, b + 1, c, 1, prev1);
    if (c < cnt[2] && prev1 != 2 && prev2 != 2)
        ret |= solve(a, b, c + 1, 2, prev1);
    return ret;
}
string trace(int a, int b, int c, int prev1, int prev2)
{
    if (a + b + c == str.size())
        return string();
    if (cache[a + 1][b][c][0][prev1] == 1)
        return string(1, 'A') + trace(a + 1, b, c, 0, prev1);
    if (cache[a][b + 1][c][1][prev1] == 1)
        return string(1, 'B') + trace(a, b + 1, c, 1, prev1);
    if (cache[a][b][c + 1][2][prev1] == 1)
        return string(1, 'C') + trace(a, b, c + 1, 2, prev1);
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> str;
    for (auto &i : str)
    {
        cnt[i - 'A']++;
    }
    int ret = solve(0, 0, 0, 0, 0);
    if (ret)
        cout << trace(0, 0, 0, 0, 0);
    else
        cout << -1;
    return 0;
}