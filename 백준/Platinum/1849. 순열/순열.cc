#include <bits/stdc++.h>

using namespace std;

int n;
int ar[100001];

inline int mid(int stt, int end) { return stt + (end - stt) / 2; }

int init(vector<int> &tree, int node, int start, int end)
{
    if (start == end) return tree[node] = 1;
    int m = mid(start, end);
    return tree[node] = init(tree, node * 2, start, m) + init(tree, node * 2 + 1, m + 1, end);
}

void update(vector<int> &tree, int node, int start, int end, int idx, int diff)
{
    if (idx < start || idx > end) return;

    tree[node] += diff;

    if (start != end)
    {
        int m = mid(start, end);
        update(tree, node * 2, start, m, idx, diff);
        update(tree, node * 2 + 1, m + 1, end, idx, diff);
    }
}

int query(vector<int> &tree, int node, int start, int end, int kth)
{
    if (start == end) return start;
    int m = mid(start, end);
    int stack_left = tree[node * 2];

    if (stack_left > kth) return query(tree, node * 2, start, m, kth);
    return query(tree, node * 2 + 1, m + 1, end, kth - stack_left);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<int> segtree(n * 4);
    init(segtree, 1, 1, n);
    
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        int val = query(segtree, 1, 1, n, x);
        ar[val] = i;
        update(segtree, 1, 1, n, val, -1);
    }

    for (int i = 1; i <= n; ++i)
        cout << ar[i] << '\n';
}