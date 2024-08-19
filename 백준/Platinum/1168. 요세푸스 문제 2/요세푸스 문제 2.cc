#include <bits/stdc++.h>
using namespace std;
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
int N, K;
int tree[400005];

void update(int left, int right, int node, int target)
{
    if (target < left || target > right)
        return;
    tree[node] -= 1;
    if (left == right)
        return;
    int mid = (left + right) / 2;
    update(left, mid, node * 2, target);
    update(mid + 1, right, node * 2 + 1, target);
}
int query(int left, int right, int node, int target)
{
    if (left == right)
        return left;
    int mid = (left + right) / 2;

    if (tree[node * 2] >= target)
        return query(left, mid, node * 2, target);
    else
        return query(mid + 1, right, node * 2 + 1, target - tree[node * 2]);
}

int main()
{
    fastio;
    memset(tree, 0, sizeof(tree));
    cin >> N >> K;
    int S = 1;
    while (N > S)
    {
        S *= 2;
    }

    for (int i = 0; i < N; i++)
    {
        tree[S + i] = 1;
    }
    for (int i = S - 1; i > 0; i--)
    {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    vector<int> answer;

    int now = 1;
    cout << "<";
    for (int i = 0; i < N; i++)
    {
        int size = N - i;
        now += K - 1;
        if (now % size == 0)
            now = size;
        else if (now > size)
            now %= size;

        int ans = query(1, S, 1, now);
        update(1, S, 1, ans);
        answer.push_back(ans);
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i == answer.size() - 1)
            break;
        cout << ", ";
    }
    cout << ">";

    return 0;
}