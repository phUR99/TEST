#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

int minTree[400005], maxTree[400005];
int arr[100005];

int T, N, Q;
void update(int left, int right, int node, int target, int val, int tree[])
{
    if (target < left || target > right)
        return;
    if (left == right)
    {
        tree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    update(left, mid, node * 2, target, val, tree);
    update(mid + 1, right, node * 2 + 1, target, val, tree);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int query(int left, int right, int node, int qleft, int qright, int tree[])
{
    if (left > qright || right < qleft)
        return -987654321;
    if (left >= qleft && right <= qright)
        return tree[node];
    int mid = (left + right) / 2;
    return max(query(left, mid, node * 2, qleft, qright, tree),
               query(mid + 1, right, node * 2 + 1, qleft, qright, tree));
}
int S;

string solve(int a, int b)
{
    int m = query(0, S - 1, 1, a, b, minTree);
    m = -m;
    int M = query(0, S - 1, 1, a, b, maxTree);
    if (m == a && M == b)
        return "YES";
    else
        return "NO";
}
int main()
{
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N >> Q;
        fill(minTree, minTree + 4 * N + 1, -987654321);
        fill(maxTree, maxTree + 4 * N + 1, 0);
        memset(arr, 0, sizeof(arr));

        S = 1;
        while (N > S)
            S *= 2;
        for (int i = 0; i < N; i++)
        {
            minTree[i + S] = -i;
            maxTree[i + S] = i;
            arr[i] = i;
        }
        for (int i = S - 1; i > 0; i--)
        {
            minTree[i] = max(minTree[i * 2], minTree[i * 2 + 1]);
            maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
        }
        int q, a, b;
        for (int i = 0; i < Q; i++)
        {
            cin >> q >> a >> b;
            if (q == 0)
            {
                swap(arr[a], arr[b]);
                update(0, S - 1, 1, a, arr[a], maxTree);
                update(0, S - 1, 1, b, arr[b], maxTree);
                update(0, S - 1, 1, a, -arr[a], minTree);
                update(0, S - 1, 1, b, -arr[b], minTree);
            }
            else
            {
                cout << solve(a, b) << '\n';
            }
        }
    }

    return 0;
}