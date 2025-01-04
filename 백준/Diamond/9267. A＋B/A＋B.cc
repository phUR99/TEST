#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define LL __int128
pair<LL, LL> solve(LL a, LL b)
{
    if (a == 1)
        return {1, 0};
    if (b == 1)
        return {0, 1};
    bool swapped = false;
    if (a < b)
    {
        swap(a, b);
        swapped = true;
    }
    LL q = a / b, r = a % b;
    pair<LL, LL> tmp = solve(r, b);
    pair<LL, LL> ret = {tmp.first, tmp.second - q * tmp.first};
    if (swapped)
        swap(ret.first, ret.second);
    return ret;
}
int main()
{
    fastio;
    ll aa, bb, ss;
    LL a, b, s;
    cin >> aa >> bb >> ss;
    a = aa, b = bb, s = ss;
    if (s == 0)
    {
        if (a > 0 && b > 0)
            cout << "NO";
        else
            cout << "YES";
        return 0;
    }
    if (a == 0)
    {
        if (b == 0)
            cout << "NO";
        else
        {
            if (s % b == 0)
                cout << "YES";
            else
                cout << "NO";
        }
        return 0;
    }
    if (b == 0)
    {
        if (s % a == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }
    if (a == s || b == s)
    {
        cout << "YES";
        return 0;
    }
    LL g = __gcd(a, b);
    if (s % g)
    {
        cout << "NO";
        return 0;
    }
    a /= g, b /= g, s /= g;
    pair<LL, LL> ret = solve(a, b);
    LL x = ret.first;
    LL y = ret.second;
    x *= s, y *= s;
    if (x < y)
    {
        swap(x, y);
        swap(a, b);
    }
    LL k = (x - 1) / b;
    y += a * k, x -= b * k;
    while (y > 0)
    {
        if (x > 0 && y > 0 && __gcd(x, y) == 1)
        {
            cout << "YES";
            return 0;
        }
        x += b;
        y -= a;
    }
    cout << "NO";

    return 0;
}