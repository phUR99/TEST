#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int cache[105][105];
const int MOD = 1e7;

int construct(int upper, int remain)
{
    if (remain == 0)
        return 1;
    int &ret = cache[upper][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int nxt = 1; nxt <= remain; nxt++)
    {
        ret += (upper + nxt - 1) * construct(nxt, remain - nxt);
        ret %= MOD;
    }
    return ret;
}

void solve()
{
    memset(cache, -1, sizeof(cache));
    int n;
    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        ret += construct(i, n - i);
        ret %= MOD;
    }

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