#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int k;
int t;
int p[105];
int n[105];
int cache[105][10005];

int solve(int idx, int remain)
{
    if (remain == 0)
        return 1;
    if (idx == k)
        return 0;
    int &ret = cache[idx][remain];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= n[idx]; i++)
    {
        int newRemain = remain - i * p[idx];
        if (newRemain < 0)
            break;
        ret += solve(idx + 1, newRemain);
    }
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> t >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p[i] >> n[i];
    }
    int ret = solve(0, t);
    cout << ret << '\n';
    return 0;
}