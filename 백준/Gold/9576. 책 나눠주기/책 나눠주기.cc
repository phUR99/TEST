#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
bool matching[1005][1005];
int aMatch[1005], bMatch[1005];
bool visited[1005];
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 1; b <= n; b++)
    {
        if (matching[a][b])
        {
            if (bMatch[b] == -1 || dfs(bMatch[b]))
            {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    memset(matching, 0, sizeof(matching));
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            matching[i][j] = 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ret++;
    }
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