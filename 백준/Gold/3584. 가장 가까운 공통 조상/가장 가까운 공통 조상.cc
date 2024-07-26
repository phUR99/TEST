#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, N, K;

int parent[20][10005];
vector<int> adj[10005];
int depth[10005];
int p , c, n;

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int k = K; k >= 0; k--)
    {
        if(diff >= (1<<k)){
            a = parent[k][a];
            diff = depth[a] - depth[b];
        }
    }
    if(a == b) return a;
    for (int k = K; k >= 0; k--)
    {
        if(parent[k][a] != parent[k][b]){
            a = parent[k][a];
            b = parent[k][b];
        }
    }    
    return parent[0][a];
}

int main(){
    fastio;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> N;
        n = N;
        K = 0;
        memset(depth, -1, sizeof(depth));
        memset(parent, 0, sizeof(parent));
        for (int i = 1; i <= N; i++)
        {
            adj[i].clear();
        }
        
        while (n > 0)
        {
            n >>= 1;
            K++;
        }
        
        for (int i = 0; i < N-1; i++)
        {
            cin >> p >> c;
            adj[p].push_back(c);
            parent[0][c] = p;
        }        
        cin >> p >> c;
        int root;
        for (int i = 1; i <= K; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }        
        }
        for (int i = 1; i <= N; i++)
        {
            if(parent[0][i] == 0){
                root = i;
                break;
            }
        }
        queue<int> q;
        depth[root] = 0;
        q.push(root);
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur])
            {
                if(depth[nxt] != -1) continue;
                depth[nxt] = depth[cur] + 1;
                q.push(nxt);
            }        
        }        
        cout << LCA(p, c) << '\n';
    }    
        
    return 0;    
}