#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, t;

int parent[10005];
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
    parent[u] = v;
    return true;
}

int MST(vector<array<int, 3>> &arr)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; i++)
    {
        int u = arr[i][1];
        int v = arr[i][2];
        int c = arr[i][0];
        if (merge(u, v))
            ret += c;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m >> t;
    vector<array<int, 3>> arr(m);
    for (auto &i : arr)
    {
        cin >> i[1] >> i[2] >> i[0];
    }
    int ret = MST(arr);
    cout << ret + (n - 1) * (n - 2) / 2 * t;
    return 0;
}