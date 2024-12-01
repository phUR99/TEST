#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
bool visited[100005];
vector<vector<pair<int, int>>> adj;
vector<int> tmp, arr;
int n, s, e;
void dfs(int here)
{
    visited[here] = true;
    if (here == e)
    {
        arr = tmp;
        return;
    }
    for (auto nxt : adj[here])
    {
        int cost = nxt.first;
        int there = nxt.second;
        if (!visited[there])
        {
            tmp.push_back(cost);
            dfs(there);
            tmp.pop_back();
        }
    }
}
int main()
{
    fastio;
    cin >> n >> s >> e;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dfs(s);
    int l = 0;
    int r = arr.size() - 1;
    int ret = 0;
    while (r - l > 0)
    {
        if (arr[r] > arr[l])
            ret += arr[l++];
        else
            ret += arr[r--];
    }
    cout << ret;
    return 0;
}