#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int u, v;
vector<int> adj[50005];
int parent[50005];

int depth[50005];
int LCA(int a, int b){    
    if(depth[a] < depth[b]) swap(a, b);
    while (depth[a] != depth[b])
    {
        a = parent[a];
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;    
}

int main(){
    fastio;
    memset(depth, -1, sizeof(depth));

    cin >> N;
    for (int i = 0; i < N -1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur])
        {
            if(depth[nxt] != -1) continue;
            depth[nxt] = depth[cur] + 1;
            parent[nxt] = cur;
            q.push(nxt);
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