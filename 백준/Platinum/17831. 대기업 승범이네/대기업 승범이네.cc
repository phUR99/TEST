#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;

vector<vector<int>> adj;
int cost[200050];
int N;
int cache[200050][2];

int solve(int cur, int state)
{
    int &ret = cache[cur][state];
    if (ret != -1)
        return ret;
    ret = 0;
    if (state)
    {
        for (auto nxt : adj[cur])
        {
            ret += solve(nxt, 0);
        }
    }
    else
    {
        int now = 0;
        for (auto nxt : adj[cur])
        {
            now += solve(nxt, 0);
        }
        ret = now;
        for (auto nxt : adj[cur])
        {
            ret = max(ret, now - solve(nxt, 0) + solve(nxt, 1) + cost[cur] * cost[nxt]);
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> N;
    adj.resize(N + 1);
    memset(cache, -1, sizeof(cache));
    for (int i = 2; i <= N; i++)
    {
        int v;
        cin >> v;
        adj[v].push_back(i);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    cout << solve(1, 0);

    return 0;
}