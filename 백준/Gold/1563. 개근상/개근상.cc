#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int cache[1005][5][5];
const int mod = 1e6;
int solve(int idx, int late, int attend)
{
    if (idx == n)
        return 1;
    int &ret = cache[idx][late][attend];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += solve(idx + 1, late, 0);

    if (late < 1)
        ret += solve(idx + 1, late + 1, 0);
    if (attend < 2)
        ret += solve(idx + 1, late, attend + 1);
    return ret %= mod;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 0, 0);
    cout << ret;
    return 0;
}