#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int indegree[1005], discovered[1005];
int n, m;
vector<vector<int>> adj;

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            discovered[i] = 1;
        }
    }
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            indegree[there]--;
            if (indegree[there] == 0)
            {
                discovered[there] = discovered[here] + 1;
                q.push(there);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << discovered[i] << ' ';
    }

    return 0;
}