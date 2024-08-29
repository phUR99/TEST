#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;

int dist_a[100005], dist_b[100005], dist_c[100005];
int tree[400005];
vector<vector<int>> arr;
vector<vector<pair<int, int>>> adj;
int n;
vector<int> compress, ABC;
int queryAnswer[100005];
bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else
    {
        return b[1] < a[1];
    }
}
void update(int l, int r, int node, int t, int v)
{
    if (t > r || t < l)
        return;
    if (l == r)
    {
        tree[node] = min(tree[node], v);
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, node * 2, t, v);
    update(mid + 1, r, node * 2 + 1, t, v);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query(int l, int r, int node, int ql, int qr)
{
    if (l > qr || r < ql)
        return 987654321;
    if (l >= ql && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return min(query(l, mid, node * 2, ql, qr), query(mid + 1, r, node * 2 + 1, ql, qr));
}
void dijkstra(int st, int dist[])
{
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (cur.first > dist[cur.second])
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] > nxt.first + cur.first)
            {
                dist[nxt.second] = nxt.first + cur.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
}

int main()
{
    fastio;
    cin >> n;
    ABC.resize(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> ABC[i];
    }
    adj.resize(n + 1);

    fill(dist_a, dist_a + n + 1, 987654321);
    fill(dist_b, dist_b + n + 1, 987654321);
    fill(dist_c, dist_c + n + 1, 987654321);
    fill(tree, tree + 4 * n + 1, 987654321);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    dijkstra(ABC[0], dist_a);
    dijkstra(ABC[1], dist_b);
    dijkstra(ABC[2], dist_c);
    arr.resize(n);
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = {dist_a[i], dist_b[i], dist_c[i], i};
        compress.push_back(dist_b[i]);
    }
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        int a = arr[i][0];
        int b = lower_bound(compress.begin(), compress.end(), arr[i][1]) - compress.begin() + 1;
        int c = arr[i][2];
        int nn = arr[i][3];
        int m = query(1, n, 1, 1, b - 1);
        if (m >= c)
        {
            queryAnswer[nn] = 1;
        }
        update(1, n, 1, b, c);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (queryAnswer[t])
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}