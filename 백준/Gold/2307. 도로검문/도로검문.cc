#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int INF = 987654321;

int distS[1005], dist[1005];
int pre[1005];
int N, M;
int MAX = -1;
vector<pair<int, int>> adj[1005];


int main(){
    fastio;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> N >> M;
    fill(distS, distS+N+1, INF);
    pq.push({0, 1});
    distS[1] = 0;
    for (int i = 0; i < M; i++)
    {
        int u, v, c ;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});

    }
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first > distS[cur.second]) continue;
        for (auto nxt : adj[cur.second])
        {
            if(distS[nxt.second] > cur.first + nxt.first){
                distS[nxt.second] = cur.first + nxt.first;
                pq.push({distS[nxt.second], nxt.second});
                pre[nxt.second] = cur.second;
            }
        }   
    }

    vector<int> track;
    int cur = N;
    while (cur != 1)
    {
        track.push_back(cur);
        cur = pre[cur];
    }
    track.push_back(1);
    reverse(track.begin(), track.end());
    for (int i = 0; i < track.size()-1; i++)
    {
        int cur = track[i];
        int nxt = track[i + 1];
        fill(dist, dist+N+1, INF);
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto tmp = pq.top(); pq.pop();
            if(tmp.first > dist[tmp.second]) continue;
            for (auto child : adj[tmp.second])
            {
                if(child.second == nxt && cur == tmp.second) continue;
                if(child.second == cur && nxt == tmp.second) continue;
                if(dist[child.second] > child.first + tmp.first){
                    dist[child.second] = child.first + tmp.first;
                    pq.push({dist[child.second], child.second});
                }
            }         
        }
        MAX = max(MAX, dist[N]);
    }
    if(MAX == INF) MAX = -1;
    else MAX -= distS[N];
    cout << MAX;


    return 0;
}