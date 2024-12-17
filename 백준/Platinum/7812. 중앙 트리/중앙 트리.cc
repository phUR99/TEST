#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
ll sum[10005];
int sub[10005];
vector<vector<pair<int, int>>> adj;

int dfs(int here)
{
    int &ret = sub[here];
    if (ret != -1)
        return ret;
    ret = 1;
    for (auto nxt : adj[here])
    {
        int cost = nxt.first;
        int there = nxt.second;
        if (sub[there] == -1)
        {
            ret += dfs(there);
            sum[0] += 1LL * cost * sub[there];
        }
    }
    return ret;
}
void find(int here, int parent, ll w)
{
    sum[here] = w;
    for (auto nxt : adj[here])
    {
        int cost = nxt.first;
        int there = nxt.second;
        if (there == parent)
            continue;
        ll nxtW = w + 1LL * cost * (n - sub[there] * 2);
        find(there, here, nxtW);
    }
}

bool solve()
{
    memset(sum, 0, sizeof(sum));
    memset(sub, -1, sizeof(sub));
    cin >> n;
    if (n == 0)
        return false;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs(0);
    find(0, -1, sum[0]);
    cout << *min_element(sum, sum + n) << '\n';
    return true;
}

int main()
{
    fastio;
    while (1)
    {
        if (!solve())
            break;
    }
    return 0;
}