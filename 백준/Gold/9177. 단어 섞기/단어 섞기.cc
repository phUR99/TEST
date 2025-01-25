#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string a, b, c;
int cache[205][205];
int matching(int i1, int i2)
{
    if (i1 + i2 == c.size())
        return 1;
    int &ret = cache[i1][i2];
    if (ret != -1)
        return ret;

    ret = 0;
    if (i1 != a.size() && a[i1] == c[i1 + i2])
        ret |= matching(i1 + 1, i2);
    if (i2 != b.size() && b[i2] == c[i1 + i2])
        ret |= matching(i1, i2 + 1);

    return ret;
}
void solve(int t)
{

    cin >> a >> b >> c;
    memset(cache, -1, sizeof(cache));
    cout << "Data set " << t << ": " << (matching(0, 0) ? "yes" : "no") << '\n';
}

int main()
{
    fastio;

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}