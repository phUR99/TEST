#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int arr[15];
int cache[5005][5005];
int n, m;
int caching(int begin, int sum)
{
    if (sum == n)
        return 0;
    if (sum > n)
        return -987654321;
    int &ret = cache[begin][sum];
    if (ret != -1)
        return ret;
    ret = -987654321;
    for (int i = 0; i < m; i++)
    {
        // cout << begin << ' ' << arr[i] << '\n';
        ret = max(ret, caching(begin + arr[i], sum + begin + arr[i]) + arr[i]);
    }
    return ret;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    memset(cache, -1, sizeof(cache));
    int ret = caching(0, 0);
    if (ret < 0)
        ret = -1;
    cout << ret << '\n';
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