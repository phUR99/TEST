#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    cout << m - __gcd(n, m);
    return 0;
}