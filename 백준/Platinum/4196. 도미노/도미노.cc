#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
vector<vector<int>> adj;
int p[100005];
bool finished[100005];
int indegree[100005];
int id;
int cnt;
int group[100005];

stack<int> s;

int solve(int cur)
{
    p[cur] = ++id;
    s.push(cur);
    int ret = p[cur];
    for (auto nxt : adj[cur])
    {
        if (p[nxt] == 0)
            ret = min(ret, solve(nxt));
        else if (!finished[nxt])
            ret = min(ret, p[nxt]);
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
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        adj.clear();
        adj.resize(N + 1);
        memset(indegree, 0, sizeof(indegree));
        memset(finished, false, sizeof(finished));
        memset(p, 0, sizeof(p));
        cnt = 0;
        id = 0;
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
        for (int i = 1; i <= N; i++)
        {
            for (auto nxt : adj[i])
            {
                if (group[i] != group[nxt])
                    indegree[group[nxt]]++;
            }
        }
        int answer = 0;
        for (int i = 0; i < cnt; i++)
        {
            answer += !indegree[i];
        }
        cout << answer << '\n';
    }

    return 0;
}