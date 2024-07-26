#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M, K;
vector<pair<int, int>> adj[40005];
int depth[40005];
int pSum[40005];
int parent[20][40005];

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    for (int k = K; k >= 0; k--)
    {
        if(diff >= (1 << k)){
            a = parent[k][a];
            diff = depth[a] - depth[b];
        }
    }
    if(a == b) return pSum[a];

    for (int k = K; k >= 0; k--)
    {
        if(parent[k][a] != parent[k][b]){
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    return pSum[parent[0][a]];
}


int main(){
    fastio;   
    cin >> N; 
    int n = N;    
    while (n > 0)
    {
        n >>=1;
        K++;
    }
    int u, v, d;
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }
    memset(depth, -1, sizeof(depth));

    cin >> M;
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    pSum[1] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if(depth[nxt.second] != -1) continue;
            depth[nxt.second] = depth[cur] + 1;
            pSum[nxt.second] = pSum[cur] + nxt.first;
            parent[0][nxt.second] = cur;
            q.push(nxt.second);            
        }        
    }
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }        
    }
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        int d1 = pSum[a];
        int d2 = pSum[b];
        int d3 = LCA(a, b);
        cout << d1 + d2 - 2 * d3 << '\n';
    }
    



    return 0;
}