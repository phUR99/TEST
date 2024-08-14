#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M, K;
vector<pair<int, int>> adj[305];
int cache[305][305];

int solution(int cur, int cnt){
    if(cur == N) return 0;
    if(cnt == M) return -987654321;
   
    int &ret = cache[cur][cnt];
    if(ret != -1) return ret;
    ret = -987654321;
    for (auto nxt : adj[cur])
    {
        ret = max(ret, nxt.first + solution(nxt.second, cnt+1));
    }
    return ret;
}


int main(){
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N >> M >> K;

    int u, v, c;
    for (int i = 0; i < K; i++)
    {
        cin >>u >> v >> c;
        if(u > v) continue;
        adj[u].push_back({c, v});
    }
    int answer = solution(1, 1);
    cout << answer;
    return 0;
}