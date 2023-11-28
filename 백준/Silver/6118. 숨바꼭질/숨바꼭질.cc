#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second


vector<int> adj[20005];
int ans[20005];

int n, m;
void bfs(int st) {
    fill(ans + 1, ans + n + 1, -1);
    ans[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (ans[nxt] != -1) continue;
            ans[nxt] = ans[cur] + 1;
            q.push(nxt);
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);       
        adj[v].push_back(u);
    }
    bfs(1);
    int M = *max_element(ans + 1, ans + n + 1);
    vector<int> v;
    for (auto i = 1; i <= n; i++)
    {
        if (ans[i] == M) v.push_back(i);
    }
    cout << v[0] << ' ' << M << ' ' << v.size();

    
}