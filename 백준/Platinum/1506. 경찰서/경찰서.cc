#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N;
vector<vector<int>> adj;
int cost[105], p[105];
int id, answer;
bool visited[105];
stack<int> s;

int find(int cur)
{
    p[cur] = ++id;
    int ret = p[cur];
    s.push(cur);

    for (auto nxt : adj[cur])
    {
        if (p[nxt] == 0)
            ret = min(ret, find(nxt));
        else if (!visited[nxt])
            ret = min(ret, p[nxt]);
    }
    if (ret == p[cur])
    {
        int minCost = 987654321;
        while (1)
        {
            int now = s.top();
            s.pop();
            visited[now] = true;
            minCost = min(minCost, cost[now]);
            if (now == cur)
                break;
        }
        answer += minCost;
    }
    return ret;
}

int main()
{
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }

    adj.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char c;
            cin >> c;
            if (c == '1')
                adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (p[i] == 0)
            find(i);
    }
    cout << answer;

    return 0;
}