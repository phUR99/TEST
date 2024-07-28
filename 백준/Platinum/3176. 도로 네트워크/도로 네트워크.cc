#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, K;
vector<pair<int, int>> adj[100005];
int parent[20][100005], minRoad[20][100005], maxRoad[20][100005];
int depth[100005];

int s = 0;
vector<int> LCA(int u, int v){
    vector<int> ret = {1000020, -1};
    if(depth[u] < depth[v]) swap(u , v);
    int diff = depth[u] - depth[v];

    for (int i = s; i >= 0; i--)
    {
        if(diff >= (1 << i)){                      
            ret[0] = min(ret[0], minRoad[i][u]);
            ret[1] = max(ret[1], maxRoad[i][u]);            
            u = parent[i][u];            
            diff = depth[u] - depth[v];
        }
    }    
    if(u == v) return ret;
    for (int i = s; i >= 0; i--)
    {
        if(parent[i][u] != parent[i][v]){
            ret[0] = min(ret[0], min(minRoad[i][u], minRoad[i][v]));
            ret[1] = max(ret[1], max(maxRoad[i][u], maxRoad[i][v]));
            u = parent[i][u];
            v = parent[i][v];                        
        }
        }
    
    ret[0] = min(ret[0], min(minRoad[0][u], minRoad[0][v]));
    ret[1] = max(ret[1], max(maxRoad[0][u], maxRoad[0][v]));
    return ret;    
}

int main(){
    fastio;
    int u, v, c;
    cin >> N;    
    int n = N;

    while (n > 0)
    {
        n >>= 1;
        s++;
    }
    for (int i = 0; i <= s; i++)
    {
        fill(minRoad[i], minRoad[i] + N + 1, 1000020);
        fill(maxRoad[i], maxRoad[i] + N + 1, -1);
    }            
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v >> c;     
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    queue<int> q;
    memset(depth, -1, sizeof(depth));
    q.push(1);
    depth[1] = 0;    
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if(depth[nxt.second] != -1) continue;
            depth[nxt.second] = depth[cur] + 1;
            parent[0][nxt.second] = cur;
            minRoad[0][nxt.second] = nxt.first;
            maxRoad[0][nxt.second] = nxt.first;
            q.push(nxt.second);            
        }        
    }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
            minRoad[i][j] = min(minRoad[i-1][j], minRoad[i-1][parent[i-1][j]]);
            maxRoad[i][j] = max(maxRoad[i-1][j], maxRoad[i-1][parent[i-1][j]]);
        }        
    }           
    cin >> K;            
    for (int i = 0; i < K; i++)
    {
        cin >> u >> v;
        vector<int> ans = LCA(u, v);
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    



    return 0;
}