#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

vector<vector<int>> adj;
int outside[200005];
bool visited[200005];
int n;
int dfs(int here)
{
    visited[here] = 1;
    int ret = 0;
    for (int there : adj[here])
    {
        if (outside[there])
            ret++;
        else if (!visited[there])
            ret += dfs(there);
    }
    return ret;
}
int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        outside[i] = c - '0';
    }
    int ret = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (outside[a] && outside[b])
            ret += 2;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && !outside[i])
        {
            int tmp = dfs(i);
            ret += tmp * (tmp - 1);
        }
    }
    cout << ret;
    return 0;
}