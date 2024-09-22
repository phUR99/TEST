#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
#define MAX 250050
using namespace std;
vector<vector<int>> adj;
int tree[MAX];
int parent[MAX];
bool visited[MAX];
bool chosen[MAX];
int cnt[MAX];

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (cnt[u] > cnt[v])
        swap(u, v);
    parent[u] = v;
    cnt[v] += cnt[u];
    cnt[u] = 0;
}
int n;
int q;
void makeTree(int cur)
{
    visited[cur] = true;
    for (int nxt : adj[cur])
    {
        if (visited[nxt])
            continue;
        tree[nxt] = cur;
        makeTree(nxt);
    }
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> q;
    vector<int> query;
    makeTree(1);
    for (int i = 0; i < q; i++)
    {
        query.clear();
        int m;
        cin >> m;
        query.resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> query[j];
            cnt[query[j]] = 1;
            chosen[query[j]] = true;
            parent[query[j]] = query[j];
        }
        for (int j = 0; j < m; j++)
        {
            if (chosen[query[j]] && chosen[tree[query[j]]])
                merge(query[j], tree[query[j]]);
        }
        long long answer = 0;
        for (int j = 0; j < m; j++)
        {
            long long N = cnt[query[j]];
            answer += (N) * (N - 1) / 2;
            cnt[query[j]] = 0;
            chosen[query[j]] = false;
            parent[query[j]] = query[j];
        }
        cout << answer << '\n';
    }

    return 0;
}