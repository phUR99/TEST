#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll solve(ll n)
{
    ll ret = n;
    for (ll i = 2; i <= n; i *= 2)
    {
        ret += (n / i) * (i / 2);
    }
    return ret;
}
int main()
{
    fastio;
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);

    return 0;
}