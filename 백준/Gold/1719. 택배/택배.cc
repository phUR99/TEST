#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int dist[205][205];
int N, M;
int table[205][205];
const int inf = 987654321;

int main(){
    fastio;
    cin >> N >> M;
    fill(&dist[0][0], &dist[200][200], inf);
    for (int i = 0; i <= N; i++) dist[i][i] = 0;        
    memset(table, -1, sizeof(table));
    int u, v, c;
    for (int i = 0; i < M; i++)
    {
        cin >>u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
        table[u][v] = v;
        table[v][u] = u;
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    table[i][j] = table[i][k];
                }                                
            }            
        }        
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(i == j) cout << "- ";
            else cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}