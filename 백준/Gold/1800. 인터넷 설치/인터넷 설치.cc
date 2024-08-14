#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int dist[1005];
const int inf = 987654321;
int N, P, K;
vector<pair<int, int>> adj[1005];
bool solve(int x){
    fill(dist, dist+N+1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for (auto nxt : adj[cur.second])
        {
            int next = cur.first + (nxt.first > x);
            if(dist[nxt.second] > next){
                dist[nxt.second] = next;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
        
    }
    return dist[N] <= K;
}


int main(){
    fastio;
    cin >> N >> P >> K;
    int u, v, c;
    for (int i = 0; i < P; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    int left= 0;
    int right = 1'000'000;
    int ans = -1;
    while (left <= right)
    {
        int mid = (left + right) /2;
        if(solve(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;

    return 0;
}