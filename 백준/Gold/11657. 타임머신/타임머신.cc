#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
vector<vector<pair<int, int>>> adj;
const int inf = 987654321;
vector<ll> bellmanFord(int src)
{
    vector<ll> upper(n + 1, inf);
    upper[src] = 0;
    bool updated;

    for (int iter = 0; iter < n; iter++)
    {
        updated = false;
        for (int here = 1; here <= n; here++)
        {
            for (auto nxt : adj[here])
            {
                int there = nxt.second;
                int cost = nxt.first;
                if (upper[here] == inf)
                    continue;
                if (upper[here] + cost < upper[there])
                {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if (!updated)
            break;
    }
    if (updated)
        upper.clear();
    return upper;
}

int main()
{
    fastio;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    vector<ll> ret = bellmanFord(1);
    if (ret.empty())
        cout << -1 << '\n';
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (ret[i] > 9e8)
                cout << -1 << '\n';
            else
                cout << ret[i] << '\n';
        }
    }

    return 0;
}