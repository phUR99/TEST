#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<pair<int, int>> arr;
ll tree[8005];

ll query(int left, int right, int node, int qleft, int qright)
{
    if (left > qright || right < qleft)
        return 0;
    if (qleft <= left && right <= qright)
        return tree[node];
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
}

void update(int left, int right, int node, int target)
{
    if (left > target || right < target)
        return;

    tree[node] += 1;
    if (left == right)
        return;
    int mid = (left + right) / 2;
    update(left, mid, node * 2, target);
    update(mid + 1, right, node * 2 + 1, target);
}

int main()
{
    fastio;
    cin >> n >> m;
    arr.resize(m);
    for (auto &i : arr)
    {
        cin >> i.first >> i.second;
    }
    sort(arr.begin(), arr.end());
    ll ret = 0;
    for (auto i : arr)
    {
        int pos = i.second;
        ll q = query(1, n, 1, pos + 1, n);
        update(1, n, 1, pos);
        ret += q;
    }
    cout << ret;
    return 0;
}