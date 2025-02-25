#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<array<int, 3>> arr;
vector<vector<int>> adj;
int parent[1035];
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    parent[u] = v;
    return true;
}

vector<vector<int>> MST()
{

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<vector<int>> ret(n + 1);
    sort(arr.begin(), arr.end());
    for (auto a : arr)
    {
        int u = a[1];
        int v = a[2];
        if (merge(u, v))
        {
            ret[u].push_back(v);
            ret[v].push_back(u);
        }
    }
    for (auto &r : ret)
    {
        sort(r.begin(), r.end());
    }

    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int d;
            cin >> d;
            arr.push_back({d, i, j});
        }
    }
    adj = MST();
    for (int i = 1; i <= n; i++)
    {
        cout << adj[i].size() << ' ';
        for (int node : adj[i])
        {
            cout << node << ' ';
        }
        cout << '\n';
    }

    return 0;
}