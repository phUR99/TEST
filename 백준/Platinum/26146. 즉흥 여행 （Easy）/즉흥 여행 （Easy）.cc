#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
vector<int> adj[200005];
vector<int> inv[200005];
bool vis[200005];

void dfs(int st) {
    
    vis[st] = true;
    for (auto nxt : adj[st])
    {
        if (!vis[nxt]) dfs(nxt);
    }
}
void dfs_inv(int st) {

    vis[st] = true;
    for (auto nxt : inv[st])
    {
        if (!vis[nxt]) dfs_inv(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inv[v].push_back(u);
    }
    dfs(1);
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) {
            flag1 =false;
            break;
        }
    }
    fill(vis + 1, vis + n + 1, false);
    dfs_inv(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) {
            flag2 = false;
            break;
        }
    }
    if (flag1 && flag2) cout << "Yes";
    else cout << "No";
}