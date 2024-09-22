#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
int parent[300005];
bool visited[300005];

int n, l;

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
    parent[u] = v;
}

int main()
{
    fastio;
    cin >> n >> l;
    for (int i = 1; i <= l; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!visited[a])
        {
            visited[a] = true;
            merge(a, b);
            cout << "LADICA\n";
            continue;
        }
        if (!visited[b])
        {
            visited[b] = true;
            merge(b, a);
            cout << "LADICA\n";
            continue;
        }
        if (!visited[find(a)])
        {
            visited[find(a)] = true;
            merge(a, b);
            cout << "LADICA\n";
            continue;
        }
        if (!visited[find(b)])
        {
            visited[find(b)] = true;
            merge(b, a);
            cout << "LADICA\n";
            continue;
        }
        cout << "SMECE\n";
    }

    return 0;
}