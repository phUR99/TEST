#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, r, counter = 0;
int discovered[100005];
vector<vector<int>> adj;
void dfs(int here)
{
    discovered[here] = ++counter;
    for (int there : adj[here])
    {
        if (discovered[there] == -1)
            dfs(there);
    }
}

int main()
{
    fastio;
    memset(discovered, -1, sizeof(discovered));
    cin >> n >> m >> r;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }

    dfs(r);
    for (int i = 1; i <= n; i++)
    {
        if (discovered[i] == -1)
            discovered[i] = 0;
        cout << discovered[i] << '\n';
    }

    return 0;
}