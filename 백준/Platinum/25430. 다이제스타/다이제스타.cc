#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll inf = 0x3fffffffffffffff;
ll dist[50050];
int n, m;
vector<pair<int, int>> adj[50050];
struct node
{
    ll dist;
    int pre, edge;
    const bool operator<(const node &a) const{
        return a.dist < dist;
    }
};

int main(){
    fastio;
    cin >> n >> m;
    fill(dist, dist+50050, inf);
    
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >>u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    int s, e;
    cin >> s >> e;
    dist[s] = 0;

    priority_queue<node> pq;
    pq.push({0, 0, s});
    while (!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        if(cur.dist > dist[cur.edge]) continue;
        for (auto nxt : adj[cur.edge])
        {
            if(cur.pre < nxt.first && dist[nxt.second] > nxt.first + cur.dist){
                dist[nxt.second] = nxt.first + cur.dist;
                int pre = nxt.first;
                pq.push({dist[nxt.second], pre, nxt.second});
            }
        }        
    }
    if(dist[e] == inf) cout << "DIGESTA";
    else cout << dist[e];

    return 0;
}