#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[1005];

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
    parent[u] = v;
}

int search(vector<vector<int>> &arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    int ret = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int c = arr[i][0];
        int u = arr[i][1];
        int v = arr[i][2];
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ret += c;
    }
    return ret;
}

int main()
{
    fastio;
    while (true)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 0)
            break;
        vector<vector<int>> arr;
        for (int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            if (c == 'B')
                arr.push_back({1, u, v});
            else
                arr.push_back({0, u, v});
        }
        sort(arr.begin(), arr.end(), greater<>());
        int M = search(arr, n);
        reverse(arr.begin(), arr.end());
        int mm = search(arr, n);
        if (mm <= k && k <= M)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}