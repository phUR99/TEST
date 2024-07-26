#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int T, N;
int adj[1005][1005];
int dist[1005];

int solution(int x){
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int i = 1; i <= N; i++)
        {
            if(!adj[cur][i] || dist[i] != -1) continue;            
            dist[i] = dist[cur] + 1;
            q.push(i);
        }        
    }
    int ret = 0;
    for (int i = 1; i <= N; i++)
    {
        ret += dist[i];
    }
    return ret;
}

int main(){
    fastio;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> adj[i][j];
            }
            
        }          
        int ans = 987654321;
        for (int i = 1; i <= N; i++)
        {            
            ans = min(ans, solution(i));
            
        }
        cout << "#" << tc << ' ';
        cout << ans << '\n';
              
    }
    
}