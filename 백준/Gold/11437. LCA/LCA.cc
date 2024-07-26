#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int u, v;
vector<int> adj[100005];
int parent[20][100005];
int depth[100005];
int K = 0;
int LCA(int a, int b){    
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = K; i >= 0; i--)
    {
        if(diff >= (1 << i)){
            a = parent[i][a];
            diff = depth[a] - depth[b];
        }
    }
    if(a == b) return a;

    for (int i = K; i >= 0; i--)
    {
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    
    return parent[0][a];
}


int main(){
    fastio;
    memset(depth, -1, sizeof(depth));

    cin >> N;
    int n = N;
    while (n > 0)
    {
        n >>= 1;
        K++;
    }
    
    for (int i = 0; i < N -1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    parent[0][1] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur])
        {
            if(depth[nxt] != -1) continue;
            depth[nxt] = depth[cur] + 1;
            parent[0][nxt] = cur;
            q.push(nxt);
        }        
    }
    for (int i = 1; i <= K; i++)
    {
        for (int u = 1; u <= N; u++)
        {
            parent[i][u] = parent[i-1][parent[i-1][u]];
        }
        
    }
    
    cin >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }        
    return 0;
}