#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int aMatch[205], bMatch[205];
int A[205], B[205];
bool adj[205][205];
bool visited[205];

bool dfs(int a)
{
    if (visited[a])
        return false;
    visited[a] = true;
    for (int b = 0; b < m; b++)
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

int main()
{
    fastio;
    cin >> n >> m;
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (B[j] <= 3 * double(A[i]) / 4 && B[j] >= double(A[i]) / 2)
                adj[i][j] = 1;
            if (B[j] >= A[i] && B[j] <= 5 * double(A[i]) / 4)
                adj[i][j] = 1;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i))
            ret++;
    }
    cout << ret;
    return 0;
}