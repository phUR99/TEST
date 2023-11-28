#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second


vector<int> adj[55];
int ans[55];
int n;
int bfs(int idx) {
    int dist[52];
    fill(dist, dist + n + 1, -1);
    dist[idx] = 0;
    queue<int> q;
    int cnt = 0;
    q.push(idx);
    while (!q.empty())
    {
        int cur = q.front(); q.pop(); 
        cnt++;
        for (auto nxt : adj[cur])
        {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    int val = *max_element(dist + 1, dist + n + 1);
    if (val == 0) return 100;
    return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (true)
    {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
    for (int i = 1; i <= n; i++)
    {
        ans[i] = bfs(i);
    }
    int mscore = *min_element(ans + 1, ans + n + 1);
    vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == mscore) vec.push_back(i);
    }
    cout << mscore << ' ' << vec.size() << '\n';
    for (auto e : vec) {
        cout << e << ' ';
    }
}