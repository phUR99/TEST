#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define ll long long
int n, m, k;
static int cnt = 1;
vector<array<int, 2>> arr;
ll tree[4000 + 5];
void update(int l, int r, int node, int t) {
  if (l > t || r < t) return;
  tree[node] += 1;
  if (l == r) return;
  int mid = (l + r) / 2;
  update(l, mid, node * 2, t);
  update(mid + 1, r, node * 2 + 1, t);
}
ll query(int l, int r, int node, int ql, int qr) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) return tree[node];
  int mid = (l + r) / 2;
  return query(l, mid, node * 2, ql, qr) +
         query(mid + 1, r, node * 2 + 1, ql, qr);
}

void solve() {
  cin >> n >> m >> k;
  memset(tree, 0, sizeof(tree));

  arr.resize(k);
  for (auto &i : arr) {
    cin >> i[0] >> i[1];
  }
  sort(arr.begin(), arr.end());
  ll ret = 0;
  for (auto &i : arr) {
    int v = i[1];
    ret += query(1, m, 1, v + 1, m);
    update(1, m, 1, v);
  }
  cout << "Test case " << cnt++ << ": " << ret << '\n';
}

int main() {
  fastio;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}