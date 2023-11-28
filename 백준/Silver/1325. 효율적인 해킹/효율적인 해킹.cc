#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second


vector<int> adj[10005];
int ans[10005];
int n, m;
int bfs(int st) {
    bool h[10005];
    fill(h + 1, h + n + 1, false);
    queue<int> q;
    q.push(st);
    h[st] = true;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {

            if (h[nxt]) continue;
            h[nxt] = true;
            q.push(nxt);
        }
    }
    int val = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h[i]) val++;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> v >> u;
        adj[u].push_back(v);        
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = bfs(i);
    }
    int Mc = *max_element(ans + 1, ans + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == Mc) cout << i << ' ';
    }

    
}