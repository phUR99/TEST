#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll arr[100005];
int n;
ll solve(ll x)
{
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += abs(i * x - arr[i]);
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll l = 1;
    ll r = 1e9;
    while (r - l >= 3)
    {
        ll a = (l * 2 + r) / 3;
        ll b = (l + 2 * r) / 3;
        if (solve(a) > solve(b))
            l = a;
        else
            r = b;
    }
    ll ret = LLONG_MAX;
    for (int i = l; i <= r; i++)
    {
        ret = min(ret, solve(i));
    }
    cout << ret;
    return 0;
}