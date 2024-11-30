#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll total = 0;
int n, m;
int parent[100005];
int find(int u)
{
    if (parent[u] == u)
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
ll MST(vector<vector<int>> &arr)
{
    ll ret = 0;
    int cnt = 0;
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u = arr[i][1];
        int v = arr[i][2];
        int c = arr[i][0];
        if (merge(u, v))
        {
            ret += c;
            cnt++;
        }
    }
    if (cnt != n - 1)
        ret = -1;
    return ret;
}

int main()
{
    fastio;
    cin >> n >> m;
    vector<vector<int>> arr(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
        total += arr[i][0];
    }
    ll cost = MST(arr);
    if (cost == -1)
        cout << -1;
    else
        cout << total - cost;

    return 0;
}