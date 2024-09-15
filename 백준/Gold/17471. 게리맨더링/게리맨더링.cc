#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
vector<vector<int>> adj;
int cost[15];
bool visited[15];
int arr[15];
int n;
int answer = 987654321;
void bfs();
void distingush(int cnt)
{
    if (cnt == n + 1)
    {
        bfs();
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        arr[cnt] = i;
        distingush(cnt + 1);
    }
}
void bfs()
{
    vector<int> score(2, 0);

    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        cnt++;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            score[arr[cur]] += cost[cur];
            for (auto nxt : adj[cur])
            {
                if (visited[nxt] || arr[cur] != arr[nxt])
                    continue;
                q.push(nxt);
                visited[nxt] = true;
            }
        }
    }
    if (cnt == 2)
        answer = min(answer, abs(score[0] - score[1]));
}

int main()
{
    fastio;

    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int c = 0; c < cnt; c++)
        {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }
    distingush(1);
    if (answer == 987654321)
        answer = -1;
    cout << answer;
    return 0;
}