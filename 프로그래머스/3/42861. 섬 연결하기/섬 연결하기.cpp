#include <bits/stdc++.h>

using namespace std;
int parent[105];
int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
    
}
bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    parent[u] = v;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){return a[2] <b[2];});
    for(auto &cost :costs){
        int u = cost[0];
        int v = cost[1];
        if(merge(u, v)) answer += cost[2];
    }
    return answer;
}