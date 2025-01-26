#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int a, b, c;
string x, y;
int cache[3005][3005];
const int NOTVISITED = 0x3f3f3f3f;
int solve(int l, int r)
{
    if (l == x.size() && r == y.size())
        return 0;
    int &ret = cache[l][r];
    if (ret != NOTVISITED)
        return ret;
    ret = -987654321;
    if (l < x.size() && r < y.size())
        ret = max(ret, solve(l + 1, r + 1) + c);
    if (l < x.size() && r < y.size() && x[l] == y[r])
        ret = max(ret, solve(l + 1, r + 1) + a);
    if (r < y.size())
        ret = max(ret, solve(l, r + 1) + b);
    if (l < x.size())
        ret = max(ret, solve(l + 1, r) + b);
    return ret;
}
int main()
{
    fastio;
    memset(cache, 0x3f, sizeof(cache));
    cin >> a >> b >> c;
    cin >> x >> y;
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}