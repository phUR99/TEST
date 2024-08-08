#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int K,N,R;
int dist[105][10050];
const int INF = 987654321;
struct node
{
    int d, l, t;
    const bool operator<(const node &a) const{
        return a.l < l;
    }
};
bool cmp(const node &a, const node &b) {
    return a.t < b.t;
}


vector<node> adj[105];
priority_queue<node> pq;
int T;

int main(){
    fastio;
    cin >> T;
    cin >> N >> K >> R;
    for (int i = 0; i <= N; i++)
    {
        fill(dist[i], dist[i]+K+1,INF);
    }
    int s, d, l, t;
    for (int i = 0; i < R; i++)
    {
        cin >> s >> d >> t >> l;
        adj[s].push_back({d, l, t});
    }
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }
    
    pq.push({1, 0, 0});
    dist[1][0] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.l > dist[cur.d][cur.t]) continue;
        for (auto nxt : adj[cur.d])
        {      
            if(cur.t + nxt.t > K) break;
            if(dist[nxt.d][cur.t + nxt.t] > cur.l + nxt.l){
                dist[nxt.d][cur.t + nxt.t] = cur.l + nxt.l;
                pq.push({nxt.d, dist[nxt.d][cur.t+nxt.t], cur.t+nxt.t});
            }
        }        
    }
    int ans = *min_element(dist[N], dist[N] + K+1);
    if(ans == 987654321){
        cout << "Poor KCM";
        return 0;
    }
    cout << ans;
    return 0;
}