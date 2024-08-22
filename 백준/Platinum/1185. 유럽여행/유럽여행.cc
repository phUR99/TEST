#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, P;
vector<vector<int>> adj, r_adj;
int answer = 0;
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int parent[20005];
int cost[10005];

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
    cin >> N >> P;

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    int u, v, c;

    for (int i = 0; i < P; i++)
    {
        cin >> u >> v >> c;
        adj.push_back({u, v, c * 2 + cost[v] + cost[u]});
    }
    sort(adj.begin(), adj.end(), cmp);
    for (int i = 0; i < P; i++)
    {
        int u = find(adj[i][0]);
        int v = find(adj[i][1]);
        if (u == v)
            continue;
        merge(u, v);
        answer += adj[i][2];
    }
    cout << answer + *min_element(cost + 1, cost + N + 1);

    return 0;
}