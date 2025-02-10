#include <string>
#include <bits/stdc++.h>

using namespace std;
bool visited[205];
void dfs(int here, vector<vector<int>> &adj){
    visited[here] = true;
    for(int there =0; there < adj[here].size(); there++){
        if(!visited[there] && adj[here][there]) dfs(there, adj);
    }
}

int solution(int n, vector<vector<int>> computers) {
    memset(visited, 0, sizeof(visited));
    int answer = 0;
    for(int i =0; i <n; i++){
        if(!visited[i]){
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}