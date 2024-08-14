#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long dist[2505][2505];
const long long inf = 0x3fffffffffffffff;
int cost[2505];
vector<pair<int, int>> adj[2505];
int N, M;

struct node
{
    int cost, nxt, price;
    const bool operator<(const node &a) const {
        return a.cost < cost;
    }
};

int main(){
    fastio;
    cin >> N >> M;
    fill(&dist[0][0], &dist[2500][2500], inf);
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    int u, v, d;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }
    priority_queue<node> pq;
    pq.push({0, 1, cost[1]});
    dist[1][cost[1]] = 0;

    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.cost > dist[cur.nxt][cur.price]) continue;
        if(cur.nxt == N) {
            cout << cur.cost;
            return 0;
        }
        for (auto child : adj[cur.nxt])
        {
            int p = min(cur.price, cost[child.second]);
            long long nxt_cost = cur.cost + cur.price * child.first;
            if(dist[child.second][cur.price] > nxt_cost){
                dist[child.second][cur.price] = nxt_cost;
                pq.push({nxt_cost, child.second, p});
            }
        }
        
    }
    


    return 0;
}