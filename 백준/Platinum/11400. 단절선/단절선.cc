#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int discovered[100005];
vector<vector<int>> adj;
set<pair<int, int>> ans;
int v, e;
int counter = 0;
int dfs(int node, int parent)
{
    discovered[node] = counter++;
    int ret = discovered[node];

    for (auto child : adj[node])
    {
        if (child == parent)
            continue;
        if (discovered[child] == -1)
        {
            int subTree = dfs(child, node);
            if (subTree > discovered[node])
            {
                pair<int, int> element = (child < node ? make_pair(child, node) : make_pair(node, child));
                ans.insert(element);
            }
            ret = min(ret, subTree);
        }
        else
            ret = min(ret, discovered[child]);
    }
    return ret;
}
int main()
{
    fastio;
    cin >> v >> e;
    adj.resize(v + 1);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(discovered, -1, sizeof(discovered));
    for (int i = 1; i <= v; i++)
    {
        if (discovered[i] == -1)
            dfs(i, -1);
    }
    cout << ans.size() << '\n';
    for (auto a : ans)
    {
        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}