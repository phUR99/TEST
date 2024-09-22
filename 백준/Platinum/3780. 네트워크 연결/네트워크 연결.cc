#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[20005];
int weight[20005];
int find(int u)
{
    if (u == parent[u])
        return u;
    int p = find(parent[u]);
    weight[u] += weight[parent[u]];
    return parent[u] = p;
}
void merge(int u, int v)
{
    weight[u] = abs(u - v) % 1000;
    parent[u] = v;
}
int t;
int n;
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            weight[i] = 0;
        }
        while (true)
        {
            char c;
            cin >> c;
            if (c == 'O')
                break;
            if (c == 'I')
            {
                int u, v;
                cin >> u >> v;
                merge(u, v);
            }
            else
            {
                int u;
                cin >> u;
                find(u);
                cout << weight[u] << '\n';
            }
        }
    }

    return 0;
}