#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int V;
vector<pair<int, int>> tree[100005];
bool visited[100005];
int mxNode, mxDist;
void dfs(int dist, int cur){
    if (visited[cur]) return;
    visited[cur] = true;

    if(dist > mxDist){        
        mxDist = dist;
        mxNode = cur;
    }
    for (auto node : tree[cur])
    {
        dfs(dist+node.first, node.second);
    }    
}

int main(){
    fastio;
    cin >> V;
    while (V--)
    {
        int edge;
        cin >> edge;
        while (true)
        {
            int u, v;
            cin >> u;
            if(u == -1) break;
            cin >> v;
            tree[u].push_back({v, edge});
            tree[edge].push_back({v, u});
        }        
    }
    dfs(0, 1);
    memset(visited, false, sizeof(visited));
    dfs(0, mxNode);
    cout << mxDist;

    return 0;
}