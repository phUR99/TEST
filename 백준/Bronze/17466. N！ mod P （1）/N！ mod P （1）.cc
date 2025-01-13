#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= m;
    }
    cout << ans;
    return 0;
}