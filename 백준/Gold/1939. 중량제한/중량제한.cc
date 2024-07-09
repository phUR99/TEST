#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int u, v, c;
vector<pair<int, int>> adj[100005];
bool visited[100005];

int main(){
    fastio;
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});    
    }
    int st, ed;

    priority_queue<pair<int, int>> pq;
    cin >> st >> ed;
    pq.push({0x7fffffff, st});
    visited[st] = true;
    int answer = 0x7fffffff;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        visited[cur.second] = true;
        answer = min(answer, cur.first);
        if(cur.second == ed) {
                cout << answer;
                return 0;
        }        
        for (auto nxt : adj[cur.second]){
            if(visited[nxt.second]) continue;
            int m = min(cur.first, nxt.first);            
            pq.push({m, nxt.second});
        }
    }    

    return 0;
}