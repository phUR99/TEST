#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int parent[300005];
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    int i;
    for (i = 2; i <= n; i++)
    {
        if (find(1) != find(i))
            break;
    }
    cout << "1 " << i;

    return 0;
}