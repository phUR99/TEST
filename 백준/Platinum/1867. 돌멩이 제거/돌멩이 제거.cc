#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
int row[505];
int col[505];
bool visited[505];
vector<vector<int>> adj;
bool dfs(int r)
{
    if (visited[r])
        return false;
    visited[r] = true;
    for (auto &c : adj[r])
    {
        if (col[c] == -1 || dfs(col[c]))
        {
            row[r] = c;
            col[c] = r;
            return true;
        }
    }
    return false;
}

int bipartiteMatching()
{
    int size = 0;
    memset(row, -1, sizeof(row));
    memset(col, -1, sizeof(col));
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
    cin >> n >> k;
    adj.resize(n + 1);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ret = bipartiteMatching();
    cout << ret;
    return 0;
}