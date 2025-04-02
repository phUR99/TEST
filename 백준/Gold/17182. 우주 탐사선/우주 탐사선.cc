#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;

vector<vector<pair<int, int>>> adj;
pair<int, int> dijkstra(int s, int e){
    int dist[15];
    int trace[15];
    memset(dist, 0x3f, sizeof(dist));
    memset(trace, -1, sizeof(trace));
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int cost = -cur.first;
        int here = cur.second;
        if(cost > dist[here]) continue;
        for (auto nxt : adj[here])
        {
            int weight = nxt.first;
            int there = nxt.second;
            if(dist[there] > cost + weight){
                dist[there] = cost + weight;
                pq.push({-dist[there], there});
                trace[there] = here;
            }
        }
        
    }
    int retDist = dist[e];
    int retState = 0;
    for (int i = e; i != -1; i = trace[i])
    {
        retState |= (1<<i);
    }
    return {retDist, retState};
    
}
int full_bit;
int cache[10][1<<10];
int solve(int st, int state){
    if(state == full_bit) return 0;
    int &ret = cache[st][state];
    if(ret != -1) return ret;

    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if(state & (1<< i)) continue;
        auto result = dijkstra(st, i);
        int nxtState = state | result.second;
        int cost = result.first;
        ret = min(ret, cost + solve(i, nxtState));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> k;
    adj.resize(n);
    full_bit = (1<<n)-1;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d;
            cin >> d;
            if(i==j) continue;
            adj[i].push_back({d, j});
        }
        
    }

    int ret = solve(k, (1 << k));
    cout << ret;
    return 0;
}