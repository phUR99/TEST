#include <bits/stdc++.h>
using namespace std;
const int MX = 987654321;
vector<int> adj[105];
bool isUsed[105];

int n;

void findCnt(int cur, int ed, int cnt){
    if(isUsed[cur] == true) return;
    isUsed[cur] = true;
    if(cur == ed) {
        cout << cnt;
        exit(0);
    }    
    for (auto nxt : adj[cur])
    {
       findCnt(nxt, ed, cnt+1);
    }
    isUsed[cur] = false;
    return;
}

int main(){
    int st, ed;
    cin >> n >> st >> ed;
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    findCnt(st, ed, 0);
    cout << -1;
    
    


    return 0;
}