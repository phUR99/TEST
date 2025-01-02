#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int parent[105];

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    parent[v] = u;
    return true;
}
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<pair<double, double>> arr(n);
    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    vector<pair<double, pair<int, int>>> adj;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto square = [](double x)
            { return x * x; };
            double dx = square(arr[i].first - arr[j].first);
            double dy = square(arr[i].second - arr[j].second);
            double dist = sqrt(dx + dy);
            adj.push_back({dist, {i, j}});
        }
    }
    sort(adj.begin(), adj.end());
    double ret = 0;
    for (auto &it : adj)
    {

        double dist = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (merge(u, v))
            ret += dist;
    }
    cout << fixed;
    cout.precision(2);
    cout << ret;

    return 0;
}