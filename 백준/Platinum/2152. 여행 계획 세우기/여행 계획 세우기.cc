#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, M, S, T;
int group[10005];
int number[10005];
int p[10005];
bool finished[10005];
int cache[10005];
int id;
int cnt;
vector<vector<int>> adj, gAdj;
/*
현재는 좀 비효율적
bfs로 수정
*/
stack<int> s;

int solve(int cur)
{
    p[cur] = ++id;
    s.push(cur);
    int ret = p[cur];
    for (auto nxt : adj[cur])
    {
        if (p[nxt] == 0)
        {
            ret = min(ret, solve(nxt));
        }
        else if (!finished[nxt])
        {
            ret = min(ret, p[nxt]);
        }
    }
    if (ret == p[cur])
    {
        while (1)
        {
            int now = s.top();
            s.pop();
            group[now] = cnt;
            number[cnt]++;
            finished[now] = true;
            if (now == cur)
                break;
        }
        cnt++;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> N >> M >> S >> T;
    adj.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
    {
        if (p[i] == 0)
            solve(i);
    }
    gAdj.resize(cnt);
    for (int i = 1; i <= N; i++)
    {
        for (auto j : adj[i])
        {
            if (group[i] != group[j])
                gAdj[group[i]].push_back(group[j]);
        }
    }
    memset(cache, 0, sizeof(cache));

    queue<int> q;
    q.push(group[S]);
    cache[group[S]] = number[group[S]];
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nxt : gAdj[cur])
        {
            if (cache[nxt] < cache[cur] + number[nxt])
            {
                cache[nxt] = cache[cur] + number[nxt];
                q.push(nxt);
            }
        }
    }
    cout << cache[group[T]] << '\n';
    return 0;
}