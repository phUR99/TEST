#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cost[1005];
int cache[1005];
int n;

int solve(int remain)
{
    if (remain == 0)
        return 0;
    int &ret = cache[remain];
    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 1; i <= remain; i++)
    {
        ret = min(ret, cost[i] + solve(remain - i));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    int ret = solve(n);
    cout << ret;
    return 0;
}