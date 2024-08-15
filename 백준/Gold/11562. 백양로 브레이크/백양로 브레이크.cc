#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int inf = 987654321;
int dist[255][255];
int n, m, k;

int main(){
    fastio;
    cin >> n >> m;
    fill(&dist[0][0], &dist[250][250], inf);
    for (int i = 0; i <= n; i++) dist[i][i] = 0;
    int u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        dist[u][v] = 0;
        dist[v][u] = !c;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
            
        }
        
    }
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        cout << dist[u][v] << '\n';
    }
    
    
    

    return 0;
}