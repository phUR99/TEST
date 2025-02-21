#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int dfs(int here, int parent){
    int ret = 0;
    for(int there : adj[here]){
        if(there == parent) continue;
        ret += dfs(there, here) +1;
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    adj.resize(n+1);    
    for(auto wire : wires){
        int u = wire[0];
        int v = wire[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i =1; i <=n; i++){
        for(int j : adj[i]){
            int diff = abs(dfs(i, j)- dfs(j, i));
            answer = min(diff , answer);
        }
    }
    return answer;
}