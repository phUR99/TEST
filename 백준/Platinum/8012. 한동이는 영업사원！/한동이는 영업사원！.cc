#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
vector<int> adj[30005];
int depth[30005];
int parent[20][30005];
int maxDepth = 0;

int returnMinDist(int a, int b){

    if(depth[a] < depth[b]) swap(a, b);
    int A = a; int B = b;
    int ret = 0;
    int dist = depth[a] - depth[b];

    for (int i = maxDepth; i >= 0; i--)
    {
        if(dist >= (1 << i)){
            a = parent[i][a];
            dist = depth[a] - depth[b];        
        }

    }
    if(a == b) return depth[A] - depth[B];
    for (int i = maxDepth; i >= 0; i--)
    {
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    a = parent[0][a];
    return (-depth[a] + depth[A]) + (depth[B] - depth[a]);
}

int main(){
    fastio;

    cin >> N;

    int n = N;
    while (n > 0)
    {
        n >>= 1;
        maxDepth++;
    }    
    int u, v;
    memset(depth, -1, sizeof(depth));

    for (int i = 0; i < N -1 ; i++)
    {
        cin >>u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (auto nxt : adj[cur])
        {
            if(depth[nxt] != -1) continue;
            depth[nxt] = depth[cur] + 1;
            parent[0][nxt] = cur;
            q.push(nxt);
        }        
    }
    for (int i = 1; i <= maxDepth; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }        
    }        

    int cur = 1;
    int nxt;
    cin >> M;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> nxt;
        ans += returnMinDist(cur, nxt);
        cur = nxt;    
    }
    cout << ans;
    return 0;
}