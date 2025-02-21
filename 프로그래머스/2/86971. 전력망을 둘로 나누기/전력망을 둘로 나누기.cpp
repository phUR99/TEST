#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> nums;

int dfs(int here, int parent){
    int &ret = nums[here] = 1;
    for(int there : adj[here]){
        if(there == parent) continue;
        ret += dfs(there, here);
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    adj.resize(n+1);  
    nums.resize(n+1, 0);
    for(auto wire : wires){
        int u = wire[0];
        int v = wire[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    for(int i =1; i <=n; i++){
        for(int j : adj[i]){
            int diff = abs(nums[i] * 2 - n);
            answer = min(diff , answer);
        }
    }
    return answer;
}