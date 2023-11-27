#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int n;
// {비용, #정점}
vector<pair<int, int>> adj[305];
// chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
bool chk[305];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        adj[i].push_back({ c, n + 1 });
        adj[n + 1].push_back({ c, i });
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            adj[i].push_back({ c,j });
        }
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    int ans = 0;
    int cnt = 0;
    chk[1] = 1;
    for (auto nxt : adj[1])
    {
        pq.push({ nxt.X, 1, nxt.Y});
    }
    while (cnt < n)
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        for (auto nxt : adj[b])
        {
            if (!chk[nxt.Y]) pq.push({ nxt.X, b, nxt.Y });
        }
    }
    cout << ans;
}