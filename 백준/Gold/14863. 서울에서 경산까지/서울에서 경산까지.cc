#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[2][105][100005];
int n, k;
pair<int, int> arr[2][105];

int solve(int way, int idx, int remain)
{
    if (idx == n)
        return 0;
    int &ret = cache[way][idx][remain];
    if (ret != -1)
        return ret;
    ret = -987654321;
    for (int i = 0; i < 2; i++)
    {
        int time = arr[i][idx].first;
        int cost = arr[i][idx].second;
        if (remain - time >= 0)
        {
            ret = max(ret, solve(i, idx + 1, remain - time) + cost);
        }
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int time, cost;
            cin >> time >> cost;
            arr[j][i] = {time, cost};
        }
    }
    int ret = max(solve(0, 0, k), solve(1, 0, k));
    cout << ret;
    return 0;
}