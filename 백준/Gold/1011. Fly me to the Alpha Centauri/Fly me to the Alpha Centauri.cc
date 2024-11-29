#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    int x, y;
    cin >> x >> y;
    ll diff = y - x;
    ll l = 0, r = 1e9;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (m * m < diff)
            l = m + 1;
        else
            r = m - 1;
    }
    ll m = l;
    int cnt = 2 * m - 1;
    if (diff <= ((m * m + (m - 1) * (m - 1)) / 2))
        cout << cnt - 1 << '\n';
    else
        cout << cnt << '\n';
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