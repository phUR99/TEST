#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool adj[105][105];
int aMatch[105], bMatch[105];
bool visited[105];
int n, m;

bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 1; b <= n; b++)
    {
        if (adj[a][b])
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

int bipartiteMatch()
{
    int size = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            size++;
    }
    return size;
}

int main()
{
    fastio;
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    int ret = bipartiteMatch();
    cout << ret;
    return 0;
}