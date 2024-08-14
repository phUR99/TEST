#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N, M;
int dist[205][205];
struct node{
    int s, e, c;
};


int main(){
    fastio;
    cin >> N >> M;
    fill(&dist[0][0], &dist[200][200], 987654321);
    for (int i = 0; i <= N; i++) dist[i][i] = 0;
    int u, v ,c;
    vector<node> edge(M);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
        edge[i] = {u, v, c};
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
            
        }        
    }
    double ans = 987654321;
    for (int i = 1; i <= N; i++)
    {
        double maxLen = 0;
        for (int j = 0; j < M; j++)
        {
            maxLen = max(maxLen, (double)(dist[i][edge[j].s] + dist[i][edge[j].e] + edge[j].c)/2);
        }
        ans = min(ans, maxLen);
    }
    cout << fixed;
    cout.precision(1);
    cout << ans;
    
    
        

    return 0;
}