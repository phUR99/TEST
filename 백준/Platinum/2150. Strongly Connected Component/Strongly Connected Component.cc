#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

vector<vector<int>> adj;
int V, E;
stack<int> s;
bool finished[10005];
vector<vector<int>> answer;
int parent[10005];
int id;
int solve(int cur)
{
    parent[cur] = ++id;
    s.push(cur);
    int ret = parent[cur];
    for (auto nxt : adj[cur])
    {
        if (parent[nxt] == 0)
            ret = min(ret, solve(nxt));
        else if (!finished[nxt])
            ret = min(ret, parent[nxt]);
    }
    if (ret == parent[cur])
    {
        vector<int> scc;
        while (1)
        {
            int now = s.top();
            s.pop();
            scc.push_back(now);
            finished[now] = true;
            if (now == cur)
                break;
        }
        sort(scc.begin(), scc.end());
        answer.push_back(scc);
    }
    return ret;
}
int main()
{
    fastio;
    cin >> V >> E;
    adj.resize(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= V; i++)
    {
        if (parent[i] == 0)
            solve(i);
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto ans : answer)
    {
        for (auto i : ans)
        {
            cout << i << ' ';
        }
        cout << "-1\n";
    }

    return 0;
}