#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int color[500005][3];
int cache[500005][3];
int words[500005];
vector<vector<int>> adj;
int n;
void solve(int here, int parent)
{
    for (int there : adj[here])
    {
        if (there == parent)
            continue;
        solve(there, here);
    }
    for (int i = 0; i < 3; i++)
    {
        cache[here][i] = color[here][i];
        for (int there : adj[here])
        {
            if (there == parent)
                continue;
            cache[here][i] += max(cache[there][(i - 1 + 3) % 3], cache[there][(i + 1) % 3]);
        }
    }
}
void trace(int here, int parent, int prev)
{
    int M = 0;
    for (int i = 0; i < 3; i++)
    {
        if (prev == i)
            continue;
        M = max(M, cache[here][i]);
    }
    int idx;
    for (idx = 0; idx < 3; idx++)
    {
        if (prev == idx)
            continue;
        if (cache[here][idx] == M)
        {
            words[here] = idx;
            break;
        }
    }
    for (int there : adj[here])
    {
        if (there == parent)
            continue;
        trace(there, here, idx);
    }
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> color[i][j];
        }
    }
    solve(1, -1);
    int ret = max({cache[1][0], cache[1][1], cache[1][2]});
    cout << ret << '\n';
    trace(1, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        switch (words[i])
        {
        case 0:
            cout << 'R';
            break;
        case 1:
            cout << "G";
            break;
        case 2:
            cout << "B";
            break;
        }
    }

    return 0;
}