#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
vector<pair<int, int>> tree[1005];

bool visited[1005];
int dist;
void findDist(int root, int target, int d){    
    if(visited[root]) return;
    if(root == target) {
        dist = d;
        return;
    }
    visited[root] = true;
    for (auto child : tree[root])
    {        
        findDist(child.second, target, d + child.first);
    }    
}

int main(){
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N-1; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        tree[a].push_back({d, b});
        tree[b].push_back({d, a});
    }    
    while (M--)
    {
        int a, b;
        
        memset(visited, false, sizeof(visited));        
        cin >> a >> b;                
        findDist(a, b, 0);
        cout << dist << '\n';
    }        
    return 0;    
}