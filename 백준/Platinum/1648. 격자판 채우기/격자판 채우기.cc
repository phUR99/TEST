#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int mod = 9901;
int n, m;
int cache[15 * 15][1 << 14];
int solve(int pos, int state)
{
    if (pos == n * m)
        return !state;
    if (pos > n * m)
        return 0;
    int &ret = cache[pos][state];
    if (ret != -1)
        return ret;
    ret = 0;
    if (state & 1)
        ret = solve(pos + 1, (state >> 1)) % mod;
    else
    {
        if (pos % m != m - 1 && !(state & (1 << 1)))
        {
            ret += solve(pos + 2, (state >> (1 << 1)));
            ret %= mod;
        }
        ret += solve(pos + 1, (state >> 1) | (1 << m - 1));
        ret %= mod;
    }

    return ret;
}
int main()
{
    fastio;
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}