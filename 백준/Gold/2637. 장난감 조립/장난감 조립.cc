#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<pair<int, int>> adj[105];
int cnt[105], idx[105];
bool base[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    fill(base, base + n, 1);
    while (m--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        base[x] = 0;
        adj[x].push_back({ y, k });
        idx[y]++;
    }
    queue<int> q;
    q.push(n);
    cnt[n] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto [nxt, c] : adj[cur])
        {
            cnt[nxt] += c * cnt[cur];
            idx[nxt]--;
            if (idx[nxt] == 0) q.push(nxt);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (base[i])  cout << i << ' ' << cnt[i] << '\n';
    }

}