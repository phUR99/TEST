#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[1005];
int cache[1005][1005];

int solve(int idx, int remain)
{
    if (idx == n)
        return 0;
    int &ret = cache[idx][remain];
    if (ret != -1)
        return ret;
    ret = 987654321;
    int val = arr[idx];
    if (val < remain)
    {
        int first = (remain != m);
        ret = min(ret, solve(idx + 1, remain - first - val));
    }
    ret = min(ret, solve(idx + 1, m - val) + remain * remain);
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, m);
    cout << ret;
    return 0;
}