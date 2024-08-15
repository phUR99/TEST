#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
bool isMcDonald[10005], isStarbucks[10005];
int dist_mc[10005], dist_st[10005];
const int inf = 987654321;
vector<pair<int, int>> adj[10050];
int n, m;
void solve(int st, int dist[]){
    fill(dist, dist+n+3, inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for (auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > nxt.first + cur.first){
                dist[nxt.second] = nxt.first + cur.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }        
    }
    
}

int main(){
    fastio;
    int u, v, c;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >>u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    int x, y, M, S, tmp;

    cin >> M >> x;
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        //adj[tmp].push_back({0, n+1});
        adj[n+1].push_back({0, tmp});
        isMcDonald[tmp] = true;

    }
    cin >> S >> y;
    for (int i = 0; i < S; i++)
    {
        cin >> tmp;
        //adj[tmp].push_back({0, n+2});
        adj[n+2].push_back({0, tmp});
        isStarbucks[tmp] = true;
    }
    solve(n+1, dist_mc);
    solve(n+2, dist_st);
    int ret = inf;

    for (int i = 1; i <= n; i++)
    {
        if(isMcDonald[i] || isStarbucks[i]) continue;
        if(dist_mc[i] > x || dist_st[i] > y) continue;
        ret = min(ret, dist_mc[i] + dist_st[i]);
    }
    if(ret == inf) cout << -1;
    else cout << ret;

    return 0;
}