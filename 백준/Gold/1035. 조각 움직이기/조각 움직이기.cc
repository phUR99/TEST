#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int dist[1 << 25];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool assemble(int state)
{
    int cnt = 0;
    vector<bool> visited(25, false);
    for (int i = 0; i < 25; i++)
    {
        if (visited[i])
            continue;
        if (state & (1 << i))
        {
            cnt++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int here = q.front();
                q.pop();
                int x = here / 5;
                int y = here % 5;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    int j = 5 * nx + ny;
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                        continue;
                    if (visited[j])
                        continue;
                    if (state & (1 << j))
                    {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }
    return cnt == 1;
}

int bfs(int st)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty())
    {
        int here = q.front();
        if (assemble(here))
            return dist[here];
        q.pop();
        for (int i = 0; i < 25; i++)
        {
            if (here & (1 << i))
            {
                int x = i / 5;
                int y = i % 5;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                        continue;
                    int there = here;
                    there &= ~(1 << i);
                    int j = 5 * nx + ny;
                    if (here & (1 << j))
                        continue;
                    there |= (1 << j);
                    if (dist[there] != -1)
                        continue;
                    dist[there] = dist[here] + 1;
                    q.push(there);
                }
            }
        }
    }
    return -1;
}

int main()
{
    fastio;
    int state = 0;
    for (int i = 0; i < 25; i++)
    {
        char c;
        cin >> c;
        if (c == '*')
            state |= (1 << i);
    }
    // cout << bitset<32>(state);
    int ret = bfs(state);
    cout << ret;
    return 0;
}