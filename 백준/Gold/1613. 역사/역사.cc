#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int n, s, K;
int dist[405][405];

int main()
{
    fastio;
    cin >> n >> K;

    fill(&dist[0][0], &dist[400][400], 987654321);
    for (int i = 0; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        int u, v;
        cin >> u >> v;
        dist[u][v] = -1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
                if (dist[i][k] == -1 && dist[k][j] == -1)
                    dist[i][j] = -1;
            }
        }
    }
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] == 987654321)
            cout << "0\n";
        else if (dist[u][v] > 0)
            cout << "1\n";
        else
            cout << "-1\n";
    }

    return 0;
}