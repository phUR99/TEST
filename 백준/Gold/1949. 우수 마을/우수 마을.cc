#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int num[10005];
int cache[10005][2];
bool visited[10005];
int N;

vector<int> adj[10005];


void dfs(int cur){
    visited[cur] = true;
    cache[cur][1] = num[cur];
    for (auto nxt : adj[cur])
    {
        if(visited[nxt]) continue;
        dfs(nxt);
        cache[cur][0] += max(cache[nxt][1], cache[nxt][0]);
        cache[cur][1] += cache[nxt][0];
    }
}

int main(){
    fastio;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
    }
    int u, v;
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << max(cache[1][0], cache[1][1]);   


    return 0;
}