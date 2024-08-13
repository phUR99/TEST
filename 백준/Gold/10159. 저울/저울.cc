#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int dist[105][105];

int main(){
    fastio;
    cin >> N >> M;
    int a, b;
    
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = -1;
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            dist[i][i] = 0;
            for (int j = 1; j <= N; j++)
            {
                if(dist[i][k] == dist[k][j] && dist[i][k] != 0) dist[i][j] = dist[i][k];
            }
            
        }        
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = N - 1;
        for (int j = 1; j <= N; j++)
        {
            if(dist[i][j] != 0) ans--;
        }
        cout << ans << '\n';
    }
    
       



    return 0;    
}