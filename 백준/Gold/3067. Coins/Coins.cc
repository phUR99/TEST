#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[25][10005];
int n;
int arr[25];

int caching(int idx, int remain)
{
    if (idx == n)
        return remain == 0;
    int &ret = cache[idx][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i * arr[idx] <= remain; i++)
    {
        ret += caching(idx + 1, remain - arr[idx] * i);
    }
    return ret;
}

void solve()
{
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int val;
    cin >> val;
    int ret = caching(0, val);
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