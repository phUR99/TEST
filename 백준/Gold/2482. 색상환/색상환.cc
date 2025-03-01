#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[2][1005][1005];
int n, k;
const int mod = 1e9 + 3;
int solve(int zero, int idx, int cnt)
{
    if (idx >= n)
        return cnt == 0;
    int &ret = cache[zero][idx][cnt];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += solve(zero, idx + 1, cnt);
    ret %= mod;
    if (!(idx == n - 1 && zero))
        ret += solve(zero, idx + 2, cnt - 1);
    ret %= mod;
    return ret;
}
int main()
{
    fastio;
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    int ret = solve(0, 1, k) + solve(1, 2, k - 1);
    ret %= mod;
    cout << ret;
    return 0;
}