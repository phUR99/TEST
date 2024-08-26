#include <cstdio>
#include <algorithm>
#define mid ((s + e) >> 1)
using namespace std;
using ll = long long;

const int N = 1e5 + 5;

ll dp[N];
ll tree[4 * N];

ll query(int node, int s, int e, int qs, int qe) {
    if (qe < s || e < qs) return -1e9;
    if (qs <= s && e <= qe) return tree[node];
    return max(query(2 * node, s, mid, qs, qe), query(2 * node + 1, mid + 1, e, qs, qe));
}

void update(int node, int s, int e, int idx, ll k) {
    if (idx < s || e < idx) return;
    if (s == e) {
        tree[node] = k;
        return;
    }
    update(2 * node, s, mid, idx, k);
    update(2 * node + 1, mid + 1, e, idx, k);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main() {
    int n, d; scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) scanf("%lld",dp + i);
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i], query(1, 0, N, max(0, i - d), i - 1) + dp[i]);
        update(1, 0, N, i, dp[i]);
    }
    printf("%lld", *max_element(dp, dp + n));
}