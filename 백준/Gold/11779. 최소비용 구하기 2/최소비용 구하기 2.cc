#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int v, e, st, ed;
vector<pair<int, int>> adj[20'005];
const int INF = 1e9 + 10;
int d[20'005];
int pre[20'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    fill(d, d + v + 1, INF);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });

    }
    cin >> st >> ed;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[st] = 0;
    pq.push({ d[st], st });
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X) continue;
        for (auto nxt : adj[cur.Y])
        {
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({ d[nxt.Y], nxt.Y });
            pre[nxt.Y] = cur.Y;
        }
    }
    cout << d[ed] << '\n';
    vector<int> ans;
    do
    {
        ans.push_back(ed);
        ed = pre[ed];
    } while (st != ed);
    ans.push_back(st);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e << ' ';
    }

}
