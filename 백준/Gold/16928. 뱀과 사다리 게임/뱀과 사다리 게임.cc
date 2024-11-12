#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int board[105];
int dist[105];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        int from, to;
        cin >> from >> to;
        board[from] = to;
    }
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (!q.empty())
    {
        auto cur = q.top();
        int e = cur.second;
        int d = cur.first;
        q.pop();
        if (dist[e] < d)
            continue;
        if (board[e])
        {
            int v = board[e];
            if (dist[v] > d)
            {
                dist[v] = d;
                q.push({dist[v], v});
            }
            continue;
        }
        for (int i = 1; i <= 6; i++)
        {
            int nxt = e + i;
            if (nxt > 100)
                continue;
            if (dist[nxt] > d + 1)
            {
                dist[nxt] = d + 1;
                q.push({dist[nxt], nxt});
            }
        }
    }
    cout << dist[100] << '\n';
    return 0;
}