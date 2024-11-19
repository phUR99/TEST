#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<vector<int>> adj;
int order[100005];
int paths[100005];
bool visited[100005];
vector<int> ans;

bool cmp(const int a, const int b)
{
    return order[b] < order[a];
}
void dfs(int here)
{
    visited[here] = true;
    for (int there : adj[here])
    {
        if (visited[there])
            continue;
        dfs(there);
    }
    ans.push_back(here);
}
int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> paths[i];
        order[paths[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    dfs(1);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        if (ans[i] != paths[i])
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}