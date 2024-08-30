#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<int> arr, q;
int tree[400005];
int n;
void update(int l, int r, int node, int t, int v)
{
    if (t > r || t < l)
        return;
    tree[node] += v;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    update(l, mid, node * 2, t, v);
    update(mid + 1, r, node * 2 + 1, t, v);
}
int query(int l, int r, int node, int t)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (tree[node * 2] >= t)
        return query(l, mid, node * 2, t);
    else
        return query(mid + 1, r, node * 2 + 1, t - tree[node * 2]);
}

int main()
{
    fastio;
    cin >> n;
    arr.resize(n);
    q.resize(n);
    vector<int> compress;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        compress.push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        update(0, n - 1, 1, i, 1);
    }
    reverse(q.begin(), q.end());
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        int now = query(0, n - 1, 1, q[i] + 1);
        answer.push_back(arr[now]);
        update(0, n - 1, 1, now, -1);
    }
    reverse(answer.begin(), answer.end());
    for (int i : answer)
    {
        cout << i << '\n';
    }

    return 0;
}