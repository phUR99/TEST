#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll fact[11];

ll calc(int f, int n)
{
    ll ret = fact[f];
    for (int i = 0; i < n; i++)
    {
        ret /= fact[f / n];
    }
    return ret;
}

ll cache[12][105][105][105];
ll solve(int floor, int r, int g, int b)
{
    if (floor == 0)
        return 1;
    // cout << floor << ' ' << r << ' ' << g << ' ' << b << '\n';
    ll &ret = cache[floor][r][g][b];
    if (ret != -1)
        return ret;
    ret = 0;
    if (floor % 3 == 0 && r >= floor / 3 && g >= floor / 3 && b >= floor / 3)
        ret += solve(floor - 1, r - floor / 3, g - floor / 3, b - floor / 3) * calc(floor, 3);
    if (floor % 2 == 0)
    {
        if (r >= floor / 2 && g >= floor / 2)
            ret += solve(floor - 1, r - floor / 2, g - floor / 2, b) * calc(floor, 2);
        if (g >= floor / 2 && b >= floor / 2)
            ret += solve(floor - 1, r, g - floor / 2, b - floor / 2) * calc(floor, 2);
        if (b >= floor / 2 && r >= floor / 2)
            ret += solve(floor - 1, r - floor / 2, g, b - floor / 2) * calc(floor, 2);
    }
    if (r >= floor)
        ret += solve(floor - 1, r - floor, g, b);
    if (g >= floor)
        ret += solve(floor - 1, r, g - floor, b);
    if (b >= floor)
        ret += solve(floor - 1, r, g, b - floor);
    return ret;
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    int n, r, g, b;
    cin >> n >> r >> g >> b;
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    ll ret = solve(n, r, g, b);
    cout << ret;
    return 0;
}