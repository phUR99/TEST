#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, R, Q;
vector<int> tree[100005];
int cache[100005];
bool visited[100005];

int solution(int node){
    if(visited[node]) return 0;
    visited[node] = true;
    int &ret = cache[node];
    if(ret != -1) return ret;
    ret = 1;
    for (auto child : tree[node])
    {
        ret += solution(child);
    }
    return ret;
}

int main(){
    fastio;
    cin >> N >> R >> Q;
    for (int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(cache, -1, sizeof(cache));    
    int ans = solution(R);
    while (Q--)
    {
        int subroot;
        cin >> subroot;
        cout << cache[subroot] << '\n';
    }
    

    return 0;
}