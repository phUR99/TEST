 #include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, k, m;

vector<int> adj[101'005];
int dist[101'005];

void dfs(int st) {
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    fill(dist + 1, dist + n +m+ 1, -1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;

            adj[n+i].push_back(x);
            adj[x].push_back(n +i);
        }
    }
    dfs(1);
    if (dist[n] == -1) cout << dist[n];
    else cout << dist[n] / 2 + 1;
}