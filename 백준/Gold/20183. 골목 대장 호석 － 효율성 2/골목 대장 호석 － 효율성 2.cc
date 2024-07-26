#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
ll N, M, A, B, C;
vector<pair<ll, ll>> adj[100005];
ll dist[100005];
const ll INF = 1LL << 63 - 1;
bool bfs(ll x){
    priority_queue<pair<ll, ll>> pq;
    fill(dist, dist+N+1, INF);
    pq.push({0, A});
    dist[A] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(-cur.first > dist[cur.second]) continue;
        for (auto nxt : adj[cur.second])
        {
            if(-cur.first + nxt.first < dist[nxt.second] && nxt.first <= x){
                dist[nxt.second] = -cur.first + nxt.first;
                pq.push({-dist[nxt.second], nxt.second});
            }
        }        
    }
    return dist[B] <= C;
}

int main(){
    fastio;
    cin >> N >> M >> A >> B >> C;
    ll u, v, c;
    ll low = INF; ll high = -1;
    ll ans = -1;
    for (int i = 0; i < M; i++)
    {
        cin >>u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        high = max(high, c);
        low = min(low, c);
    }        
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if(bfs(mid)){
            high = mid - 1;
            ans = mid;
        }
        else low = mid + 1;
    }
    cout << ans;
    return 0;
}