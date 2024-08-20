#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

vector<int> tree[400005];
int last_ans;
int n, m;
int s;
int query(int left, int right, int node, int qleft, int qright, int target)
{
    if (left > qright || right < qleft)
        return 0;
    if (left >= qleft && right <= qright)
        return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), target) - tree[node].begin());
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qleft, qright, target) + query(mid + 1, right, node * 2 + 1, qleft, qright, target);
}

int main()
{
    fastio;
    cin >> n;
    s = 1;
    while (n > s)
        s *= 2;
    int t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        tree[s + i].push_back(t);
    }
    for (int i = s - 1; i > 0; i--)
    {
        for (auto e : tree[i * 2])
        {
            tree[i].push_back(e);
        }
        for (auto e : tree[i * 2 + 1])
        {
            tree[i].push_back(e);
        }
    }
    for (int i = 1; i <= 4 * n; i++)
    {
        sort(tree[i].begin(), tree[i].end());
    }
    cin >> m;
    int i, j, k;
    while (m--)
    {
        cin >> i >> j >> k;
        last_ans = query(1, s, 1, i, j, k);
        cout << last_ans << '\n';
    }
    return 0;
}