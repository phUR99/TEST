#include <bits/stdc++.h>

using namespace std;
#define ll long long
bool vis[505];
vector<int> graph[505];
int ans = 0;
void dfs() {
    
    stack<int> s;
    s.push(1);
    while (!s.empty())
    {
        vis[1] = true;
        int cur = s.top(); s.pop();
        for (auto e : graph[cur])
        {
            if (vis[e]) continue;
            vis[e] = 1;
            ans++;
            if (cur == 1) s.push(e);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs();
    cout << ans;
}