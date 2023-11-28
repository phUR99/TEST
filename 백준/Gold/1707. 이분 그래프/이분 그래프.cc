#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second


vector<int> adj[20005];
int ans[20005];
int n, m;
bool bfs(int st) {
    queue<int> q;
    q.push(st);
    ans[st] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur]) {
            if (ans[nxt] == ans[cur]) {
                return false;
            }
            if (ans[nxt] == 0) {
                q.push(nxt);
                ans[nxt] = -ans[cur];
            }

        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }        
        fill(ans + 1, ans + n + 1, 0);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool f = true;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 0) {
               f = bfs(i) & f;               
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    

    
}