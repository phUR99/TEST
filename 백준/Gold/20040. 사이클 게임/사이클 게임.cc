#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, m;
int parent[500'005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
bool uni(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return true;
    if(u > v) swap(u, v);
    parent[v] = u;    
    return false;
}

int main(){
    fastio;
    cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        parent[i] = i;        
    }
    int answer = 0;

    for(int i =1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;        

        if(uni(u, v)) {            
            answer = i;            
            cout << answer;
            return 0;
        }        
    }
    cout << answer << '\n';
    


    return 0;
} 