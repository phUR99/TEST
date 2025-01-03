#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
int dist[1005];
vector<vector<pair<int, int>>> adj;
bool solve(int x)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        auto here = q.front();
        q.pop();
        for (auto nxt : adj[here])
        {
            int d = nxt.first;
            int there = nxt.second;
            if (dist[there] == -1 && d <= x)
            {
                dist[there] = dist[here] + 1;
                q.push(there);
            }
        }
    }
    int ed = n + 2 - 1;
    if (dist[ed] == -1)
        return false;
    return dist[ed] - 1 <= k;
}

int main()
{
    fastio;
    cin >> n >> k;
    vector<pair<int, int>> arr = {{0, 0}};
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    arr.push_back({10000, 10000});
    adj.resize(arr.size());
    auto square = [](int x)
    { return x * x; };
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int dx = square(arr[i].first - arr[j].first);
            int dy = square(arr[i].second - arr[j].second);
            int dist = (int)sqrt(dx + dy) / 10;
            int remain = (sqrt(dx + dy) - (int)sqrt(dx + dy) + dist * 10 > 0);
            adj[i].push_back({dist + remain, j});
            adj[j].push_back({dist + remain, i});
        }
    }

    int l = 0;
    int r = 1000000005;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}