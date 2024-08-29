#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int dist[305][305];
int n, m, t;
int main()
{
    fastio;
    cin >> n >> m >> t;
    fill(&dist[0][0], &dist[300][300], 987654321);
    for (int i = 0; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        dist[u][v] = min(dist[u][v], h);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > max(dist[i][k], dist[k][j]))
                {
                    dist[i][j] = max(dist[i][k], dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == 987654321)
            cout << "-1\n";
        else
            cout << dist[u][v] << '\n';
    }

    return 0;
}