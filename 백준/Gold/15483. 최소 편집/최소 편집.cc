#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[1005][1005];
string a, b;

int solve(int l, int r)
{
    if (l == a.size() || r == b.size())
        return max(a.size() - l, b.size() - r);
    int &ret = cache[l][r];
    if (ret != -1)
        return ret;
    ret = 987654321;
    if (a[l] == b[r])
        ret = min(ret, solve(l + 1, r + 1));
    ret = min(ret, solve(l, r + 1) + 1);
    ret = min(ret, solve(l + 1, r) + 1);
    ret = min(ret, solve(l + 1, r + 1) + 1);
    return ret;
}

int main()
{
    fastio;
    cin >> a >> b;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}