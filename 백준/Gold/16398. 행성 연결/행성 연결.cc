#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int adj[1005][1005];
int parent[1005];

struct node{
    int weight, u, v;
    const bool operator<(const node &a) const{
        return weight < a.weight;
    }
};
int N;
vector<node> arr;

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void uni(int u, int v){
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
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> adj[i][j];
            if(i != j) arr.push_back({adj[i][j], i, j});
        }
        
    }    
    sort(arr.begin(), arr.end());
    long long ans = 0;
    int cnt = 0;    
    for (auto cur : arr)
    {        
        if(isParentSame(cur.u, cur.v)) continue;
        else{
            ans += cur.weight;
            uni(cur.u, cur.v);
            cnt++;
        }        
        if(cnt == N -1) break;
    }
    cout << ans;


    return 0;
}