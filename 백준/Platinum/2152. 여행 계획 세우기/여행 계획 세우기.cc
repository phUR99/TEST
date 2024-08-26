#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N, M, S, T;
int group[10005];
int p[10005];
bool finished[10005];
int cache[10005];

int id;
int cnt;
vector<vector<int>> adj, gAdj;

stack<int> s;
int find(int nowGroup)
{
    int cur = 0;
    for (int i = 1; i <= N; i++)
    {
        cur += (nowGroup == group[i]);
    }
    if (nowGroup == group[T])
        return cur;
    int &ret = cache[nowGroup];
    if (ret != -1)
        return ret;
    ret = -987654321;

    for (auto nxtG : gAdj[nowGroup])
    {
        ret = max(ret, find(nxtG) + cur);
    }
    return ret;
}

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
    memset(cache, -1, sizeof(cache));
    int answer = find(group[S]);
    if (answer <= 0)
        cout << 0;
    else
        cout << answer;
    return 0;
}