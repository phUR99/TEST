#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll fact[1000005];
const int MOD = 1e9 + 7;
ll inverse(int k, ll v)
{
    if (k == 0)
        return 1;
    if (k & 1)
        return v * inverse(k - 1, v) % MOD;
    ll half = inverse(k / 2, v) % MOD;
    return half * half % MOD;
}
int main()
{
    fastio;
    int n, r;
    cin >> n >> r;
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    ll answer = fact[n] % MOD * inverse(MOD - 2, fact[r]) % MOD * inverse(MOD - 2, fact[n - r]) % MOD;
    cout << answer;
    return 0;
}