#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll n, m;
ll prime[15];
ll cache[1 << 10];
void solve(int state)
{
    ll &ret = cache[state];
    if (ret != -1)
        return;
    ret = 0;
    ll d = 1;
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & state)
            d *= prime[i];
    }
    ret += m / d;
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & state)
            continue;
        int nxtState = ((1 << i) | state);
        solve(nxtState);
    }
}

int main()
{
    fastio;
    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> prime[i];
    }
    solve(0);
    ll ret = 0;
    for (int state = (1 << n) - 1; state; state--)
    {
        if (__builtin_popcount(state) % 2)
            ret += cache[state];
        else
            ret -= cache[state];
    }
    cout << ret;
    return 0;
}