#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[300005];
bool solve(ll x)
{
    ll ret = 0;
    for (int i = 0; i < m; i++)
    {
        ret += arr[i] / x + (arr[i] % x != 0);
    }
    return ret <= n;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    ll l = 1;
    ll r = 1e9;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (solve(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}