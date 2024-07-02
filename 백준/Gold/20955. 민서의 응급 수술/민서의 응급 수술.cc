#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M;

vector<int> tree[100'005];
bool visited[100'005];
int pcnt = 0;

void dfs(int root){
    if(visited[root]) return;

    visited[root] = true;
    for (auto child : tree[root])
    {
        dfs(child);
    }        
}

int main(){
    fastio;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);        
        tree[b].push_back(a);      
    }
    queue<int> q;
    
    for (int i = 1; i <= N; i++)
    {
        if(visited[i]) continue;        
        dfs(i);
        pcnt++;
    }    
    cout << pcnt - 1 + (M + pcnt - 1) - (N - 1);

    return 0;
}