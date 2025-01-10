#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool adj[305][305];
int row[305], col[305];
bool visited[305];
int r, c, n;
bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 1; b <= c; b++)
    {
        if (!adj[a][b])
            continue;
        if (col[b] == -1 || dfs(col[b]))
        {
            row[a] = b;
            col[b] = a;
            return true;
        }
    }
    return false;
}

int main()
{
    fastio;
    cin >> r >> c >> n;
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            adj[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 0;
    }
    int ret = 0;
    for (int i = 1; i <= r; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ret++;
    }
    cout << ret;
    return 0;
}