#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[1005];
//d[i] : i번째의 부분 수열 중에서 가장 길이가 긴 값.
bool vis[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> graph[1005];
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = true;
        ans++;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto nxt :graph[cur])
            {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << ans;
}