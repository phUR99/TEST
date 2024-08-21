#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int tree[400005];
int pos[100005];
int ord[100005];
int T;
int N;

void update(int left, int right, int node, int target)
{
    if (target < left || target > right)
        return;
    tree[node] += 1;

    if (left == right)
        return;
    int mid = (left + right) / 2;
    update(left, mid, node * 2, target);
    update(mid + 1, right, node * 2 + 1, target);
}
int query(int left, int right, int node, int qleft, int qright)
{
    if (left > qright || right < qleft)
        return 0;
    if (left >= qleft && right <= qright)
        return tree[node];
    int mid = (left + right) / 2;
    return query(left, mid, node * 2, qleft, qright) + query(mid + 1, right, node * 2 + 1, qleft, qright);
}

int main()
{
    fastio;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        memset(tree, 0, sizeof(tree));
        int S = 1;
        while (N > S)
        {
            S *= 2;
        }
        for (int i = 0; i < N; i++)
        {
            cin >> pos[i];
        }
        int p;
        for (int i = 0; i < N; i++)
        {
            cin >> p;
            ord[p] = i;
        }
        long long answer = 0;
        for (int i = 0; i < N; i++)
        {
            int lim = ord[pos[i]];
            answer += query(0, S - 1, 1, lim + 1, N);
            update(0, S - 1, 1, lim);
        }
        cout << answer << '\n';
    }
    return 0;
}