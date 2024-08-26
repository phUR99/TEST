#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

#define ll long long
using namespace std;
vector<vector<int>> adj;
ll n;
ll answer = 0;
bool visited[300005];
ll dfs(int cur)
{
    visited[cur] = true;
    ll ret = 1;
    for (auto nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        ll k = dfs(nxt);
        answer += (n - k) * k + k * (k - 1) / 2;
        ret += k;
    }
    return ret;
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
    dfs(1);
    cout << answer;
    return 0;
}