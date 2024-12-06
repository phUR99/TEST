#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    ll a, b;
    cin >> a >> b;
    cout << b / __gcd(a, b) * a;
    return 0;
}