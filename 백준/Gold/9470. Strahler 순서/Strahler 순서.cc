#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

void solve()
{
    int k, m, p;
    cin >> k >> m >> p;
    vector<vector<int>> adj(m + 1);
    vector<int> indegree(m + 1);
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<pair<int, int>> order(m + 1, {0, 0});
    queue<int> q;
    for (int i = 1; i <= m; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            order[i] = {1, 1};
        }
    }
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {

            if (order[there].first < order[here].first)
                order[there] = {order[here].first, 1};
            else if (order[there].first == order[here].first)
                order[there] = {order[here].first, order[there].second + 1};
            indegree[there]--;
            if (indegree[there] == 0)
            {
                q.push(there);
                order[there].first = (order[there].second > 1) ? order[there].first + 1 : order[there].first;
            }
        }
    }
    cout << k << ' ' << order[m].first << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}