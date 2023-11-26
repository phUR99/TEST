#include <bits/stdc++.h>

using namespace std;
#define ll long long

int deg[32005];
vector<int> adj[32005];

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
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<>> pq;    
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if(deg[i]==0) pq.push(i);
    }
    while (!pq.empty())
    {
        int cur = pq.top(); pq.pop();
        res.push_back(cur);
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0) pq.push(nxt);
        }
    }
    for (auto e : res) {
        cout << e << ' ';
    }
}