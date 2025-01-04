#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;
    ll s0 = 1, t0 = 0, r0 = -n;
    ll s1 = 0, t1 = 1, r1 = k;
    ll tmp;
    while (r1)
    {
        ll q = r0 / r1;
        tmp = r0 - r1 * q;
        r0 = r1, r1 = tmp;

        tmp = s0 - s1 * q;
        s0 = s1, s1 = tmp;

        tmp = t0 - t1 * q;
        t0 = t1, t1 = tmp;
    }
    if (abs(r0) != 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    ll x = s0 / r0;
    ll y = t0 / r0;
    while (y <= 0 || x <= 0)
    {
        x += k;
        y += n;
        if (y > 1e9)
            break;
    }
    if (y > 1e9)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << y << '\n';
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