#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, p;
int capacity[405][405], flow[405][405];
int parent[405];
int networkFlow(int src, int sink)
{
    int totalFlow = 0;
    while (1)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(src);
        parent[src] = src;
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 1; there <= n; there++)
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
        int amount = 987654321;
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
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        capacity[a][b]++;
        // capacity[b][a]++;
    }
    int ret = networkFlow(1, 2);
    cout << ret << '\n';
    return 0;
}