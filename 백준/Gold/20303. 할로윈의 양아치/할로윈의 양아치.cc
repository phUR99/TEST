#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m, k, s;
bool visited[30050];
int candies[30050];
vector<vector<int>> adj;
vector<pair<int, int>> arr;
int cache[3005];

pair<int, int> bfs(int st)
{
    visited[st] = true;
    queue<int> q;
    int ret = 0;
    int cnt = 0;
    q.push(st);

    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        ret += candies[here];
        cnt++;
        for (int there : adj[here])
        {
            if (!visited[there])
            {
                visited[there] = true;
                q.push(there);
            }
        }
    }
    if (cnt >= k)
        ret = 0;
    return {cnt, ret};
}

int main()
{
    fastio;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> candies[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            arr.push_back(bfs(i));
            if (arr.back().first >= k)
                arr.pop_back();
        }
    }
    s = arr.size();
    for (int i = 0; i < s; i++)
    {
        for (int j = k - 1; j - arr[i].first >= 0; j--)
        {
            cache[j] = max(cache[j], cache[j - arr[i].first] + arr[i].second);
        }
    }
    cout << cache[k - 1];
    return 0;
}