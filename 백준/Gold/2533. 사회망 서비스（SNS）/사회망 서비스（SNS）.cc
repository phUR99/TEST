#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
vector<int> adj[1'000'005];
int cache[1'000'005][2];

int solution(int prev, int cur, int curState){
\
    int &ret = cache[cur][curState];
    if(ret != -1) return ret;
    ret = curState;

    for (auto child : adj[cur])
    {
        if(prev == child) continue;

        int tmp = 987654321;
        if(curState){
            tmp = min(solution(cur, child, 0), solution(cur, child, 1));
        }
        else{
            tmp = solution(cur, child, 1);
        }
        ret += tmp;
    }    
    return ret;
}

int main(){
    fastio;

    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(cache, -1, sizeof(cache));        
    int ans = min(solution(-1, 1, 1), solution(-1, 1, 0));
    cout << ans;
    return 0;
}