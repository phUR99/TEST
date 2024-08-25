#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int T;
vector<vector<int>> adj;
int p[100005], indegree[100005], group[100005];
int cnt;
int id;
bool finished[100005];
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
            finished[now] = true;
            group[now] = cnt;
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
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        adj.clear();
        adj.resize(N);
        cnt = 0;
        id = 0;
        memset(p, 0, sizeof(p));
        memset(indegree, 0, sizeof(indegree));
        memset(group, 0, sizeof(group));
        memset(finished, 0, sizeof(finished));
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 0; i < N; i++)
        {
            if (p[i] == 0)
                solve(i);
        }
        for (int i = 0; i < N; i++)
        {
            for (auto nxt : adj[i])
            {
                if (group[nxt] != group[i])
                    indegree[group[nxt]]++;
            }
        }
        vector<int> ans;
        int notCnt = 0, ansGroup;
        for (int i = 0; i < cnt; i++)
        {
            if (indegree[i] == 0)
            {
                ansGroup = i;
                notCnt++;
            }
        }
        if (notCnt > 1)
            cout << "Confused\n";
        else
        {
            for (int i = 0; i < N; i++)
            {
                if (group[i] == ansGroup)
                    ans.push_back(i);
            }
            for (auto i : ans)
            {
                cout << i << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}