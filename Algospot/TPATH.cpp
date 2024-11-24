#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<array<int, 3>> adj;
int parent[2005];
int find(int u)
{
    if (u == parent[u])
        return u;
    return find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}
int n, m;
// MST를 구성하면서 0번 노드와 N-1번 노드를 이을 수 있는가?
bool MST(int lower, int upper)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int u = adj[i][1];
        int v = adj[i][2];
        int c = adj[i][0];
        if (c >= lower && c <= upper)
            merge(u, v);
    }
    return find(0) == find(n - 1);
}

void solve()
{

    cin >> n >> m;
    adj.clear();
    adj.resize(m);
    vector<int> weight;
    for (int i = 0; i < m; i++)
    {
        cin >> adj[i][1] >> adj[i][2] >> adj[i][0];
        weight.push_back(adj[i][0]);
    }
    sort(adj.begin(), adj.end());
    sort(weight.begin(), weight.end());
    int l = 0;
    int r = 0;
    int ret = 987654321;
    while (l < m && r < m)
    {
        // 상한이 확정되면 그보다 더 큰 상한값에는 시도하지 않아도 됨(대신 하한값을 올려서 시도)

        if (MST(weight[l], weight[r]))
        {
            ret = min(ret, weight[r] - weight[l]);
            l++;
        }
        else
            r++;
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