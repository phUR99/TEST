#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int v, e;
vector<vector<int>> adj;
int discovered[10500];
bool curVertex[10500];
int counter = 0;

int dfs(int here, bool isRoot)
{
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for (auto nxt : adj[here])
    {
        if (discovered[nxt] == -1)
        {
            children++;
            int subtree = dfs(nxt, false);
            if (!isRoot && subtree >= discovered[here])
                curVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[nxt]);
    }
    if (isRoot)
        curVertex[here] = (children >= 2);
    return ret;
}

int main()
{
    fastio;
    cin >> v >> e;
    memset(discovered, -1, sizeof(discovered));
    adj.resize(v + 1);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= v; i++)
    {
        if (discovered[i] == -1)
            dfs(i, true);
    }
    vector<int> ret;
    for (int i = 1; i <= v; i++)
    {
        if (curVertex[i])
            ret.push_back(i);
    }
    cout << ret.size() << '\n';
    for (auto i : ret)
    {
        cout << i << ' ';
    }

    return 0;
}