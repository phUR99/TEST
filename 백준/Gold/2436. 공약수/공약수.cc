#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int gcd, lcm;
    cin >> gcd >> lcm;
    int m = lcm / gcd;
    int x;
    int sum = 987654321;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0 && (m / i + i) * gcd < sum && __gcd(gcd * i, gcd * (m / i)) == gcd)
        {
            x = i;
            sum = (m / i + i) * gcd;
        }
    }
    cout << x * gcd << ' ' << (m / x) * gcd;

    return 0;
}