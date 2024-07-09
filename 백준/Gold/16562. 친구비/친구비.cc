#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M, K;
int u, v;
int cost[10005];
int parent[10005];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(cost[u] < cost[v]) swap(u, v);
    parent[u] = v;
}


int main(){
    fastio;

    set<int> fri;

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];    
        parent[i] = i;
    }
    while (M--)
    {
        cin >> u >> v;
        merge(u, v);
    }
    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        if(fri.find(find(i)) != fri.end()) continue;
        answer += cost[parent[i]];
        if(answer > K) {
            cout << "Oh no";
            return 0;
        }
        fri.insert(parent[i]);
    }
    
    
    cout << answer;

    return 0;
}