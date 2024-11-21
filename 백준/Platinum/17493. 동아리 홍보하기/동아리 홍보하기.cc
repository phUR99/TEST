#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
bool visited[200005];
vector<vector<int>> adj;
int answer = 0;
const int NEEDED = 0;
const int UNNEED = 1;
const int STITCH = 2;

int dfs(int here)
{
    visited[here] = true;
    vector<int> state(3, 0);
    for (int there : adj[here])
    {
        if (visited[there])
            continue;
        state[dfs(there)]++;
    }
    if (state[NEEDED])
    {
        answer++;
        return STITCH;
    }
    if (state[STITCH])
        return UNNEED;
    return NEEDED;
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i) == NEEDED)
            answer++;
    }
    cout << answer;
    return 0;
}