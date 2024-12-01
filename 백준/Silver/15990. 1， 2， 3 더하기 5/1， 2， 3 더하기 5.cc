#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const int MOD = 1e9 + 9;
int cache[4][100005];
int solve(int prev, int remain)
{
    if (remain == 0)
        return 1;
    int &ret = cache[prev][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 1; i <= min(3, remain); i++)
    {
        if (i == prev)
            continue;
        ret += solve(i, remain - i);
        ret %= MOD;
    }
    return ret % MOD;
}
int main()
{
    fastio;
    int t;
    cin >> t;
    memset(cache, -1, sizeof(cache));
    while (t--)
    {
        int n;
        cin >> n;
        int ret = solve(0, n);
        cout << ret << '\n';
    }

    return 0;
}