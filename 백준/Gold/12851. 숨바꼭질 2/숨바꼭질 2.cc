#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int dist[100005];
int n, m;

int main()
{
    fastio;
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;

    queue<pair<int, int>> q;
    q.push({0, n});
    int cnt = 0;
    while (!q.empty())
    {
        int here = q.front().second;
        int cost = q.front().first;
        q.pop();
        if (here == m)
        {
            if (dist[here] == -1)
            {
                dist[here] = cost;
            }
            else if (dist[here] != cost)
                continue;
            cnt++;
        }
        dist[here] = cost;
        int there;
        there = here - 1;
        if (there >= 0 && dist[there] == -1)
            q.push({cost + 1, there});
        there = here + 1;
        if (there <= 100000 && dist[there] == -1)
            q.push({cost + 1, there});
        there = here * 2;
        if (there <= 100000 && dist[there] == -1)
            q.push({cost + 1, there});
    }
    cout << dist[m] << '\n'
         << cnt;
    return 0;
}