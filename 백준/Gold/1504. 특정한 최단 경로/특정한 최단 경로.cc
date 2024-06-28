#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<pair<int, int>> adj[805];
int N, E;
int v1,v2;
int dist[805];
const int INF = 987654321;

struct node
{
    int cost, to;
    const bool operator<(const node &a) const{
        return a.cost < cost;
    }
};

int main(){
    fastio;
    cin >> N >> E;

    while (E--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
        adj[to].push_back({cost, from});                
    }
    cin >> v1 >> v2;
    int one2v1, n2v1, one2v2, n2v2, v12v2;
    dist[v1] = 0;
    priority_queue<node> pq;
    
    fill(dist+1, dist+N+1, INF);
    pq.push({0, v1});
    dist[v1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.to] < cur.cost) continue;
        for (auto e : adj[cur.to])
        {
            if (dist[e.second] > cur.cost + e.first){
                dist[e.second] = cur.cost + e.first;
                pq.push({dist[e.second], e.second});
            }
        }        
    }
    one2v1 = dist[1]; n2v1 = dist[N]; v12v2 = dist[v2];

    fill(dist+1, dist+N+1, INF);
    pq.push({0, v2});
    dist[v2] = 0;       
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.to] < cur.cost) continue;
        for (auto e : adj[cur.to])
        {
            if (dist[e.second] > cur.cost + e.first){
                dist[e.second] = cur.cost + e.first;
                pq.push({dist[e.second], e.second});
            }
        }        
    }
    one2v2 = dist[1]; n2v2 = dist[N];    
    int d1 = one2v1 + n2v2;
    int d2 = one2v2 + n2v1;    
    if(min(d1, d2) > INF || v12v2 == INF) {
        cout << -1;
        return 0;
    }
    cout << min(d1, d2) + v12v2;
    
    return 0;
}