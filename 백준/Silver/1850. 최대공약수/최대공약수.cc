#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll a, b;
int main()
{
    fastio;
    cin >> a >> b;
    ll n = __gcd(a, b);
    while (n--)
    {
        cout << "1";
    }

    return 0;
}