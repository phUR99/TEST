#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<int>> adj, gAdj;
int cost[500050], gCost[500050], cache[500050], p[500050];
int group[500050];
bool finished[500050], isStore[500050], store[500500];
bool visited[500050];

int N, M, st, P, id, cnt;
stack<int> s;
int solve(int cur)
{
    p[cur] = ++id;
    int ret = p[cur];
    s.push(cur);
    for (auto nxt : adj[cur])
    {
        if (p[nxt] == 0)
            ret = min(ret, solve(nxt));
        if (!finished[nxt])
            ret = min(ret, p[nxt]);
    }
    if (ret == p[cur])
    {
        while (1)
        {
            int now = s.top();
            s.pop();
            finished[now] = true;
            group[now] = cnt;
            gCost[cnt] += cost[now];
            if (store[now])
                isStore[cnt] = true;
            if (now == cur)
                break;
        }
        cnt++;
    }
    return ret;
}
int answer = 0;

int main()
{
    fastio;
    cin >> N >> M;
    adj.resize(N + 1);
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    cin >> st >> P;
    for (int i = 0; i < P; i++)
    {
        int t;
        cin >> t;
        store[t] = true;
    }
    for (int i = 1; i <= N; i++)
    {
        if (p[i] == 0)
            solve(i);
    }
    gAdj.resize(cnt);
    for (int i = 1; i <= N; i++)
    {
        for (int j : adj[i])
        {
            if (group[i] != group[j])
                gAdj[group[i]].push_back(group[j]);
        }
    }
    queue<int> q;
    cache[group[st]] = gCost[group[st]];
    q.push(group[st]);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : gAdj[cur])
        {
            if (cache[nxt] < cache[cur] + gCost[nxt])
            {
                cache[nxt] = cache[cur] + gCost[nxt];
                q.push(nxt);
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (isStore[i])
            answer = max(answer, cache[i]);
    }

    cout << answer;

    return 0;
}