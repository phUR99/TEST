#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

vector<vector<int>> adj;
int N, M;
bool visited[1005];
int worked[1005];

bool solve(int cur)
{
    visited[cur] = true;
    for (auto nxt : adj[cur])
    {
        if (worked[nxt] == 0 || !visited[worked[nxt]] && solve(worked[nxt]))
        {
            worked[nxt] = cur;
            return true;
        }
    }
    return false;
}
int main()
{
    fastio;
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        if (solve(i))
            answer++;
    }
    cout << answer;
    return 0;
}