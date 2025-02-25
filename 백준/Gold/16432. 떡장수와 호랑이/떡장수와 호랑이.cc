#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool arr[1005][10];
int cache[1005][10];
int n;
int solve(int idx, int prev)
{
    if (idx == n)
        return cache[idx][prev] = 1;
    int &ret = cache[idx][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == prev)
            continue;
        if (arr[idx][i])
            ret |= solve(idx + 1, i);
    }
    return ret;
}
void dfs(int idx, int prev)
{
    if (idx == n)
        return;
    for (int i = 0; i < 10; i++)
    {
        if (i == prev)
            continue;
        if (cache[idx + 1][i] && arr[idx][i])
        {
            cout << i << '\n';
            dfs(idx + 1, i);
            return;
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int idx;
            cin >> idx;
            arr[i][idx] = 1;
        }
    }
    int ret = solve(0, 0);

    if (ret)
    {
        dfs(0, 0);
    }
    else
    {
        cout << -1;
    }
    return 0;
}