#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int l[2005], r[2005];
int cache[2005][2005];

int n;
int solve(int lidx, int ridx)
{
    if (lidx == n || ridx == n)
        return 0;
    int &ret = cache[lidx][ridx];
    if (ret != -1)
        return ret;
    ret = solve(lidx + 1, ridx);
    if (l[lidx] > r[ridx])
        ret = max(ret, solve(lidx, ridx + 1) + r[ridx]);
    ret = max(ret, solve(lidx + 1, ridx + 1));
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}