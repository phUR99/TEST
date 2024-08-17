#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int V, E;
vector<int> answer;
vector<int> adj[1005];

bool visited[1005];

void solve(int cur){    
    visited[cur] = true;
    for (auto e : adj[cur])
    {
        if(!visited[e]) solve(e);
    }
    answer.push_back(cur);        
}

int main(){
    fastio;
    for (int test_case = 1; test_case <= 10; test_case++)
    {
        cin >> V >> E;
        answer.clear();
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= V; i++)
        {
            adj[i].clear();
        }
        int u, v;
        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        for (int i = 1; i <= V; i++)
        {
            if(!visited[i]) solve(i);
        }
        reverse(answer.begin(), answer.end());
        cout << "#" << test_case << ' ';
        for (auto &ans : answer)
        {
            cout << ans << ' ';
        }
        cout << '\n';
    }
    

    return 0;
}