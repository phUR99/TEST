#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll n, ans;

int main()
{
    fastio;
    cin >> n;
    ans = n;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        ans -= ans / i;
        while (n % i == 0)
            n /= i;
    }

    if (n > 1)
        ans -= ans / n;
    cout << ans;

    return 0;
}