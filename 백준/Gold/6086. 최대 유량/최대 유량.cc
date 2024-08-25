#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int cap[52][52];
int flow[52][52];

vector<vector<int>> adj;
int visited[52];
int answer;
int ctoi(char c)
{
    if (c <= 'Z')
    {
        return c - 'A';
    }
    return c - 'a' + 26;
}
int solve(int source, int sink)
{
    while (true)
    {
        memset(visited, -1, sizeof(visited));
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto nxt : adj[cur])
            {
                if (cap[cur][nxt] - flow[cur][nxt] > 0 && visited[nxt] == -1)
                {
                    q.push(nxt);
                    visited[nxt] = cur;
                    if (nxt == sink)
                        break;
                }
            }
            if (visited[sink] != -1)
                break;
        }
        if (visited[sink] == -1)
            break;
        int ret = 987654321;
        int res;
        for (int i = sink; i != source; i = visited[i])
        {
            res = cap[visited[i]][i] - flow[visited[i]][i];
            ret = min(ret, res);
        }
        for (int i = sink; i != source; i = visited[i])
        {
            flow[visited[i]][i] += ret;
            flow[i][visited[i]] -= ret;
        }
        answer += ret;
    }
    return answer;
}
int N;
int main()
{
    fastio;
    cin >> N;
    char u, v;
    int c;
    adj.resize(52);
    for (int i = 0; i < N; i++)
    {
        cin >> u >> v >> c;
        int ui = ctoi(u);
        int vi = ctoi(v);
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
        cap[ui][vi] += c;
        cap[vi][ui] += c;
    }
    cout << solve(ctoi('A'), ctoi('Z')) << '\n';

    return 0;
}