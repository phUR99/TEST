#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;

bool visited[10005];
int mxCost, mxNode;
vector<pair<int, int>> tree[10005];

void dfs(int cur, int dist){
    if(visited[cur]) return;
    visited[cur] = true;

    if(mxCost < dist){
        mxCost = dist;
        mxNode = cur;
    }
    for (auto [nxtDist, nxt] : tree[cur])
    {        
        dfs(nxt, dist + nxtDist);
    }
    
}

int main(){
    fastio;
    cin >> N;
    
    
    for (int i = 0; i < N-1; i++)        
    {
        int p, c, d;
        cin >> p >> c >> d;
        tree[p].push_back({d, c});
        tree[c].push_back({d, p});
    }    
    int u = 0;
    int M = 0;    
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(mxNode, 0);
    cout << mxCost;        

    return 0;
}