#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll factorial[1000005];
const ll MOD = 1e9 + 7;
ll inv(int val, int pow)
{
    if (pow == 0)
        return 1;
    if (pow & 1)
        return inv(val, pow - 1) * val % MOD;
    ll half = inv(val, pow / 2) % MOD;
    // cout << half << '\n';
    return half * half % MOD;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= MOD;
    }
    ll ret = 1LL * factorial[n] % MOD * inv(factorial[n - m], MOD - 2) % MOD * inv(factorial[m], MOD - 2) % MOD;
    cout << ret;
    return 0;
}