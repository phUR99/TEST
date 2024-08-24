#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, M, Q;
int dist[505][505];
int cache[505][505];
vector<pair<int, int>> arr;

int main()
{
    fastio;
    cin >> N >> M >> Q;
    arr.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
        cache[i][i] = arr[i].first;
    }
    sort(arr.begin() + 1, arr.end());

    fill(&dist[0][0], &dist[500][500], 987654321);
    for (int i = 0; i <= N; i++)
    {
        dist[i][i] = 0;
    }
    int u, v, c;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        cache[u][v] = max(cache[u][u], cache[v][v]);
        cache[v][u] = max(cache[u][u], cache[v][v]);
        dist[u][v] = c;
        dist[v][u] = c;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int i1 = arr[i].second;
                int j1 = arr[j].second;
                int k1 = arr[k].second;
                if (dist[i1][j1] + cache[i1][j1] > dist[i1][k1] + dist[k1][j1] + max(cache[i1][k1], cache[k1][j1]))
                {
                    dist[i1][j1] = dist[i1][k1] + dist[k1][j1];
                    cache[i1][j1] = max(cache[i1][k1], cache[k1][j1]);
                }
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> u >> v;
        if (dist[u][v] == 987654321)
            cout << -1 << '\n';
        else
            cout << dist[u][v] + cache[u][v] << '\n';
    }

    return 0;
}