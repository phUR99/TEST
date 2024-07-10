#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M, K;
int blue[4000005];
int parent[4000005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void uni(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(u > v) swap(u, v);
    parent[u] = v;
}
int main(){
    fastio;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >>blue[i];
    }
    sort(blue, blue+M);
    for (int i = 0; i <= M; i++)
    {
        parent[i] = i;
    }    
    for (int i = 0; i < K; i++)
    {
        int cur;
        cin >> cur;
        int idx = find(upper_bound(blue, blue+M, cur) - blue);        
        cout << blue[idx] << '\n';
        uni(idx, idx + 1);
    }    

    
    return 0;
}