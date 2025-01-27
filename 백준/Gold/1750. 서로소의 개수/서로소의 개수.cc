#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int arr[55];
const int MOD = 1e7 + 3;
int cache[55][100005];

int solve(int idx, int gcd)
{
    if (idx == n)
        return gcd == 1;
    int &ret = cache[idx][gcd];
    if (ret != -1)
        return ret;
    ret = 0;
    if (gcd == 0)
        ret += solve(idx + 1, arr[idx]);
    else
        ret += solve(idx + 1, __gcd(gcd, arr[idx]));
    ret %= MOD;
    ret += solve(idx + 1, gcd);
    return ret %= MOD;
}
int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}