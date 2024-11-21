#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<vector<int>> adj;
bool visited[1005];
int answer;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALL = 2;

int dfs(int here)
{
    visited[here] = true;
    vector<int> status(3, 0);
    for (auto there : adj[here])
    {
        if (visited[there])
            continue;
        status[dfs(there)]++;
    }
    if (status[UNWATCHED])
    {
        answer++;
        return INSTALL;
    }
    if (status[INSTALL])
        return WATCHED;
    return UNWATCHED;
}

void solve()
{
    answer = 0;
    memset(visited, 0, sizeof(visited));
    int g, h;
    cin >> g >> h;
    adj.clear();
    adj.resize(g);
    while (h--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < g; i++)
    {
        if (!visited[i] && dfs(i) == UNWATCHED)
            answer++;
    }
    cout << answer << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}