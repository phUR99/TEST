#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll n, a;

int main()
{
    fastio;
    cin >> n >> a;
    ll r0 = n, r1 = a;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;
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
    cout << n - a << ' ';
    if (r0 != 1)
        cout << -1;
    else
    {
        cout << (t0 + n) % n;
    }
    return 0;
}