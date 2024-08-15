#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
const ll inf = 0x3fffffffffffffff;
map<int, ll> dist[50050];
int n, m;
vector<pair<ll, int>> adj[50050];
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
    
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >>u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        dist[u][c] = inf;
        dist[v][c] = inf;
    }
    int s, e;
    cin >> s >> e;
    dist[s][0] = 0;

    priority_queue<node> pq;
    pq.push({0, 0, s});
    ll answer = inf;
    while (!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        if(cur.edge == e) answer = min(answer, cur.dist);
        if(cur.dist > dist[cur.edge][cur.pre]) continue;
        for (auto nxt : adj[cur.edge])
        {
            if(cur.pre < nxt.first && dist[nxt.second][nxt.first] > cur.dist + nxt.first){
                dist[nxt.second][nxt.first] = nxt.first + cur.dist;
                int pre = nxt.first;
                pq.push({nxt.first + cur.dist, pre, nxt.second});
            }
        }        
    }
    if(answer == inf) cout << "DIGESTA";
    else cout << answer;
    
    return 0;
}