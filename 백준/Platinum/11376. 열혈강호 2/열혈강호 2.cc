#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int capacity[2005][2005], flow[2005][2005];
int parent[2005];
const int INF = 987654321;
int networkFlow(int src, int sink)
{
    int totalFlow = 0;
    while (1)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        parent[src] = src;
        q.push(src);
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 0; there <= n + m + 1; there++)
            {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[sink] == -1)
            break;
        int amount = INF;
        for (int p = sink; p != src; p = parent[p])
        {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = sink; p != src; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int works;
        cin >> works;
        for (int work = 0; work < works; work++)
        {
            int w;
            cin >> w;
            capacity[w][i + m] = INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        capacity[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        capacity[m + i][m + n + 1] = 2;
    }
    int ret = networkFlow(0, m + n + 1);
    cout << ret << '\n';
    return 0;
}