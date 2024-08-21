#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int T;
int N, M;
bool visited[505];
vector<vector<int>> adj;

int main()
{
    fastio;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> N >> M;
        adj.clear();
        adj.resize(N + 1);
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        visited[1] = 1;
        int cnt = 0;
        for (auto nxt : adj[1])
        {
            q.push(nxt);
            visited[nxt] = true;
            cnt++;
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur])
            {
                if (visited[nxt])
                    continue;
                cnt++;
                visited[nxt] = true;
            }
        }
        cout << "#" << test_case << ' ' << cnt << '\n';
    }

    return 0;
}