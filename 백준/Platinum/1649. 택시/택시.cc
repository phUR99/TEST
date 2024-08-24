#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, M, K;
int st, ed;
int cache[1005][1005];
vector<vector<int>> adj;

bool isMid[1005];
int solve(int cur, int cnt)
{
    if (cur == ed)
    {
        if (cnt == K)
            return 1;
        else
            return 0;
    }

    int &ret = cache[cur][cnt];
    if (ret != -1)
        return ret;
    ret = 0;
    for (auto nxt : adj[cur])
    {
        if (isMid[cur])
            ret += solve(nxt, cnt + 1);
        else
            ret += solve(nxt, cnt);
    }

    return ret;
}

int main()
{
    fastio;
    cin >> N >> M;
    adj.resize(N + 1);
    memset(cache, -1, sizeof(cache));
    int u, v;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cin >> st >> ed;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int t;
        cin >> t;
        isMid[t] = true;
    }
    int answer = solve(st, 0);
    cout << answer;
    return 0;
}