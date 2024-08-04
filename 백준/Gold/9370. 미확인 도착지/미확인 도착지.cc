#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int INF = 987654321;
#define SIZE 2005
vector<pair<int, int>> adj[SIZE];
int dist_s[SIZE], dist_g[SIZE], dist_h[SIZE];

void init(int x){
    for (int i = 1; i <= x; i++)
    {
        adj[i].clear();
    }
    fill(dist_s, dist_s+SIZE, INF);
    fill(dist_g, dist_g+SIZE, INF);
    fill(dist_h, dist_h+SIZE, INF);
}
void dk(int dist[], int st){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({0, st});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for (auto nxt : adj[cur.second])
        {
            if(dist[nxt.second] > cur.first + nxt.first){
                dist[nxt.second] = cur.first + nxt.first;
                pq.push({dist[nxt.second], nxt.second});
            }
        }        
    }    
}

int T;
int n, m ,t;
int s, g, h;
int u, v, c;

int main(){
    fastio;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        init(n);
        
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> c;
            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }
        vector<int> arr(t, 0);
        for (int i = 0; i < t; i++)
        {
            cin>> arr[i];
        }
        sort(arr.begin(), arr.end());
        dk(dist_s, s);
        dk(dist_g, g);
        dk(dist_h, h);
        for (auto cur : arr)
        {
            int minDist = min(dist_h[s] + dist_g[cur], dist_h[cur]+ dist_g[s]) + dist_h[g];
            if (minDist == dist_s[cur]) cout << cur << ' ';
        }        
        cout << '\n';

    }
    

    return 0;
}