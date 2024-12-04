#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int a, b, c, d;
int bfs()
{
    map<pair<int, int>, int> dist;
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[{0, 0}] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int wa = cur.first;
        int wb = cur.second;
        if (dist.count({wa, 0}) == 0)
        {
            dist[{wa, 0}] = dist[cur] + 1;
            q.push({wa, 0});
        }
        if (dist.count({0, wb}) == 0)
        {
            dist[{0, wb}] = dist[cur] + 1;
            q.push({0, wb});
        }
        if (dist.count({wa, b}) == 0)
        {
            dist[{wa, b}] = dist[cur] + 1;
            q.push({wa, b});
        }
        if (dist.count({a, wb}) == 0)
        {
            dist[{a, wb}] = dist[cur] + 1;
            q.push({a, wb});
        }
        if (dist.count({min(wa + wb, a), max(0, wa + wb - a)}) == 0)
        {
            dist[{min(wa + wb, a), max(0, wa + wb - a)}] = dist[cur] + 1;
            q.push({min(wa + wb, a), max(0, wa + wb - a)});
        }
        if (dist.count({max(0, wa + wb - b), min(wa + wb, b)}) == 0)
        {
            dist[{max(0, wa + wb - b), min(wa + wb, b)}] = dist[cur] + 1;
            q.push({max(0, wa + wb - b), min(wa + wb, b)});
        }
    }
    if (dist.count({c, d}) == 0)
        return -1;
    return dist[{c, d}];
}

int main()
{
    fastio;
    cin >> a >> b >> c >> d;
    int ret = bfs();
    cout << ret;
    return 0;
}