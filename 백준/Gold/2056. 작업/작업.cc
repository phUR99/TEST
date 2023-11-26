#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<int> adj[10005];
int cost[10005]; 
int idx[10005];
int tot[10005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t, k;
        cin >> t >> k;
        cost[i] = t;
        while (k--)
        {
            int v;
            cin >> v;
            adj[v].push_back(i);
            idx[i]++;
        }
    }
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (idx[i] == 0) {
            q.push(i);
            tot[i] = cost[i];
        }

    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (auto nxt : adj[cur])
        {
            tot[nxt] = max(tot[nxt], tot[cur] + cost[nxt]);
            idx[nxt]--;
            if (idx[nxt] == 0) q.push(nxt);

        }
    }
    cout << *max_element(tot + 1, tot + n + 1);
}