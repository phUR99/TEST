#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
string command = "DSLR";
int st, ed;
bool visited[10005];
int parent[10005];
int cmd[10005];
const int MOD = 10000;

int execute(int start, int cmd)
{
    int ret = 0;
    switch (cmd)
    {
    case 0:
        ret = 2 * start % MOD;
        break;
    case 1:
        ret = (start - 1 + MOD) % MOD;
        break;
    case 2:
        ret = start * 10;
        ret = (ret % MOD) + (ret / MOD);
        break;
    case 3:
        ret = start / 10 + (start % 10) * 1000;
        break;
    }
    return ret;
}

void solve()
{
    cin >> st >> ed;
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    memset(cmd, -1, sizeof(cmd));
    parent[st] = st;
    visited[st] = true;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int there = execute(here, dir);
            if (visited[there])
                continue;
            visited[there] = true;
            parent[there] = here;
            cmd[there] = dir;
            q.push(there);
        }
    }
    stack<int> s;
    for (int p = ed; p != st; p = parent[p])
    {
        s.push(cmd[p]);
    }
    while (!s.empty())
    {
        cout << command[s.top()];
        s.pop();
    }

    cout << '\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}