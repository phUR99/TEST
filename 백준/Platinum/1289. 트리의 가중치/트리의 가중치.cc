#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<vector<pair<int, int>>> adj;
ll cache[100005][2];
const ll MOD = 1e9 + 7;
void dfs(int here, int parent)
{
    ll sum = 0;
    for (auto nxt : adj[here])
    {
        int cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;
        dfs(there, here);
        cache[here][0] += cache[there][0] + cache[there][1];
        cache[here][0] %= MOD;
        cache[here][1] += (cache[there][1] + 1LL) * (ll)cost;
        cache[here][1] %= MOD;
    }

    for (auto nxt : adj[here])
    {

        int cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;
        ll value = (sum % MOD * (cache[there][1] + 1LL) % MOD) * (ll)cost % MOD;
        sum += (cache[there][1] + 1LL) * (ll)cost;
        sum %= MOD;
        cache[here][0] += value;
        cache[here][0] %= MOD;
    }
    // cout << "HERE: " << here << ' ' << cache[here][0] << ' ' << cache[here][1] << '\n';
}

int main()
{
    fastio;
    cin >> n;
    adj.resize(n + 1);
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs(1, -1);
    cout << (cache[1][0] + cache[1][1]) % (MOD);
    return 0;
}