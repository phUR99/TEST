#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[100005];
int tree[400005];

int returnIdx(int i1, int i2)
{
    if (i1 == -1)
        return i2;
    if (i2 == -1)
        return i1;
    return (arr[i1] > arr[i2]) ? i1 : i2;
}
void update(int l, int r, int n, int t)
{
    if (l > t || r < t)
        return;
    if (l == r)
    {
        tree[n] = t;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, n * 2, t);
    update(m + 1, r, n * 2 + 1, t);
    tree[n] = returnIdx(tree[n * 2], tree[n * 2 + 1]);
}
int query(int l, int r, int n, int ql, int qr)
{
    if (l > qr || r < ql)
        return -1;
    if (l >= ql && r <= qr)
        return tree[n];
    int m = (l + r) / 2;
    return returnIdx(query(l, m, n * 2, ql, qr), query(m + 1, r, n * 2 + 1, ql, qr));
}
int main()
{
    fastio;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(1, n, 1, i);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1)
        {
            arr[u] = v;
            update(1, n, 1, u);
        }
        else
        {
            int i = query(1, n, 1, u, v);
            int i2 = returnIdx(query(1, n, 1, u, i - 1), query(1, n, 1, i + 1, v));
            cout << arr[i] + arr[i2] << '\n';
        }
    }

    return 0;
}