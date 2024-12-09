#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[1005][50];
int n, s, m;
int arr[1005];

int solve(int start, int idx)
{
    if (idx == n)
        return cache[start][idx] = 1;
    int &ret = cache[start][idx];
    if (ret != -1)
        return ret;
    ret = 0;
    if (start + arr[idx] <= m)
        ret |= solve(start + arr[idx], idx + 1);
    if (start - arr[idx] >= 0)
        ret |= solve(start - arr[idx], idx + 1);
    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(s, 0);
    if (!ret)
    {
        cout << -1;
        return 0;
    }
    for (int i = m; i >= 0; i--)
    {
        if (cache[i][n] == 1)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}