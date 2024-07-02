#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
bool visited[505];
vector<int> tree[505];
bool isTree;
int cnt;

void dfs(int prev, int cur){
    if(visited[cur]){
        isTree = false;
        return;
    }
    visited[cur] = true;
    for (auto nxt : tree[cur]){
            if(nxt == prev) continue;
            dfs(cur, nxt);
    }    
}

int main(){
    fastio;
    while (true)
    {
        int n, m, u, v;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++)
            tree[i].clear();

        while (m--)
        {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int treeCount = 0;
        for (int i = 1; i <= n; i++)
        {
            if(visited[i]) continue;
            isTree = true;            
            dfs(-1, i);            
            treeCount += isTree;
        }
        cout << "Case " << ++cnt << ": ";
        if (!treeCount)
            cout << "No trees." << '\n';
        else if (treeCount == 1)
            cout << "There is one tree." << '\n';
         else
            cout << "A forest of " << treeCount << " trees." << '\n';
    }
    

    return 0;
}