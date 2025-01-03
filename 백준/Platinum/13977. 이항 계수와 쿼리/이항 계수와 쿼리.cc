#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
const ll MX = 4e6;
const ll MOD = 1e9 + 7;
ll fact[MX + 5];
void precalc()
{
    fact[0] = 1;
    for (int i = 1; i <= MX; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
}
ll inv(ll value, int t)
{
    if (t == 0)
        return 1;
    if (t & 1)
        return value * inv(value, t - 1) % MOD;
    ll half = inv(value, t / 2);
    return half * half % MOD;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << fact[n] * inv(fact[n - k], MOD - 2) % MOD * inv(fact[k], MOD - 2) % MOD << '\n';
}
int main()
{
    fastio;
    precalc();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}