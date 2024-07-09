#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int G, P, g;
int parent[100005];

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}
void uni(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(u > v) swap(u, v);
    parent[v] = u;
}

int main(){
    fastio;
    cin >> G >> P;
    int answer = 0;
    for(int i = 0; i <= G; i++) parent[i] = i;
    for(int p = 0; p < P; p++)
    {
        cin >> g;
        g = find(g);        
        if(g == 0) break;
        answer = p + 1;
        uni(g, g-1);
    }
    cout << answer;


    return 0;
}