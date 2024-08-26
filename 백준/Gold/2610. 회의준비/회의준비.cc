#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int dist[105][105];
int parent[105];
int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main()
{
    fastio;
    fill(&dist[0][0], &dist[100][100], 987654321);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int cnt = N;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
        u = find(u);
        v = find(v);
        if (u != v)
        {
            cnt--;
            merge(u, v);
        }
    }
    cout << cnt << '\n';
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> answer;
    for (int k = 1; k <= N; k++)
    {
        int ret = 987654321;
        int idx = 987654321;
        for (int i = 1; i <= N; i++)
        {
            if (find(i) != k)
                continue;
            int cur = 0;
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] == 987654321)
                    continue;
                cur = max(cur, dist[i][j]);
            }
            if (ret > cur)
            {
                idx = i;
                ret = cur;
            }
        }
        if (ret != 987654321)
            answer.push_back(idx);
    }

    sort(answer.begin(), answer.end());
    for (int i : answer)
    {
        cout << i << '\n';
    }

    return 0;
}