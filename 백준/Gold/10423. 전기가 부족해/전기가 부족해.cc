#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M, K;

int powerPlant[1005];

int parent[1005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    parent[u] = v;    
}
bool isParentSame(int u, int v){
    return find(u) == find(v);
}

int main(){
    fastio;

    int u, v, w;
    cin >> N >> M >> K;
    if(K == N) {
        cout << 0;
        return 0;
    }
    vector<pair<int, pair<int, int>>> adj(M);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < K; i++)
    {
        cin >> powerPlant[i];
    }
    for (int i = 1; i < K; i++)
    {
        merge(powerPlant[0], powerPlant[i]);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> adj[i].second.first >> adj[i].second.second >> adj[i].first;
    }
    sort(adj.begin(), adj.end());
    int cnt = K-1;
    int ans = 0;


    for (size_t i = 0; i < M; i++)
    {
        if(isParentSame(adj[i].second.first, adj[i].second.second)) continue;
        merge(adj[i].second.first, adj[i].second.second);
        ans += adj[i].first;
        cnt++;
        if(cnt == N -1) break;
    }
    cout << ans;
    

    return 0;
}