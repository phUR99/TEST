#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int p, w, c, v;
int parent[1005];
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
    cin >> p >> w >> c >> v;
    vector<vector<int>> arr(w, vector<int>(3));
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    }
    for (int i = 0; i < p; i++)
    {
        parent[i] = i;
    }

    sort(arr.begin(), arr.end(), greater<>());
    for (int i = 0; i < w; i++)
    {
        int width = arr[i][0];
        int uu = arr[i][1];
        int vv = arr[i][2];
        merge(uu, vv);
        if (find(c) == find(v))
        {
            cout << width;
            return 0;
        }
    }

    return 0;
}