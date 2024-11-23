#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> adj;
int n;
bool visited[105];
bool dfs(int here, int start)
{
    visited[here] = true;
    for (int there : adj[here])
    {
        if (there == start)
            return true;
        if (visited[there])
            continue;
        return dfs(there, start);
    }
    return false;
}
int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int e;
        cin >> e;
        adj[i].push_back(e);
    }
    int ret = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        if (dfs(i, i))
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}