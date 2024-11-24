#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dist[205][205];
int v, n, m;

void floyd(int k)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

void solve()
{
    memset(dist, 0x3f, sizeof(dist));

    cin >> v >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int i = 0; i < v; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        floyd(i);
    }
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] <= c)
        {
            ret++;
            continue;
        }
        dist[a][b] = c;
        dist[b][a] = c;
        floyd(a);
        floyd(b);
    }
    cout << ret << '\n';
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