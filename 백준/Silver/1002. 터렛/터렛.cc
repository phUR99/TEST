#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double r = (r1 + r2) * (r1 + r2);
    double l = (r1 - r2) * (r1 - r2);
    if (dist == 0)
    {
        if (l == 0)
            cout << "-1\n";
        else
            cout << "0\n";
    }
    else if (dist == r || dist == l)
        cout << "1\n";
    else if (l < dist && dist < r)
        cout << "2\n";
    else
        cout << "0\n";
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