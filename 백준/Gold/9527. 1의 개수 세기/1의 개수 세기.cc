#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
map<ll, ll> prefix;
ll a, b;
ll solve(ll num)
{
    ll ret = 0;
    ll offset = 0;
    while (num)
    {
        ll val = 1;
        while (val <= num)
        {
            val <<= 1;
        }
        val >>= 1;
        ret += prefix[val - 1] + offset * (val);
        num -= val;
        // cout << val << ' ' << num << '\n';
        offset++;
    }

    return ret + offset;
}

int main()
{
    fastio;
    prefix[0] = 0;
    for (int i = 1; i < 64; i++)
    {
        prefix[(1LL << i) - 1] = 2 * prefix[(1LL << (i - 1)) - 1] + (1LL << (i - 1));
    }
    cin >> a >> b;
    a = solve(a - 1);
    b = solve(b);
    cout << b - a << '\n';
    return 0;
}