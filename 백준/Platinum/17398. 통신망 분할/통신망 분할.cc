#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define ll long long
int N, M, Q;
int parent[100005];
ll number[100005];
bool queried[100005];

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
    if (number[u] >= number[v])
        swap(u, v);
    parent[u] = v;
    number[v] += number[u];
    number[u] = 0;
}

int main()
{
    fastio;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        number[i] = 1;
    }
    vector<pair<int, int>> query;
    query.resize(M + 1);

    for (int i = 1; i <= M; i++)
    {
        cin >> query[i].first >> query[i].second;
    }
    vector<int> order(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> order[i];
        queried[order[i]] = true;
    }
    reverse(order.begin(), order.end());
    for (int i = 1; i <= M; i++)
    {
        if (queried[i] == false)
        {
            int u = find(query[i].first);
            int v = find(query[i].second);
            merge(u, v);
        }
    }

    ll answer = 0;
    for (int i = 0; i < Q; i++)
    {
        int u = find(query[order[i]].first);
        int v = find(query[order[i]].second);
        if (u != v)
        {
            answer += number[u] * number[v];
            merge(u, v);
        }
    }
    cout << answer;

    return 0;
}