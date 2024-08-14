#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int dist[205][205];
const int inf = 987654321;
int pos[205];
int N, M, K;

int main(){
    fastio;
    fill(&dist[0][0], &dist[200][200], inf);
    
    
    cin >> N >> M;
    int u, v, c;
    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++)
    {   
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> pos[i];
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
    vector<pair<int, int>> ans;

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 0; j < K; j++)
        {
            sum = max(sum, dist[pos[j]][i] + dist[i][pos[j]]);
        }
        ans.push_back({sum, i});        
    }
    sort(ans.begin(), ans.end());
    for (auto nxt : ans)
    {
        if(ans.front().first < nxt.first) break;
        cout << nxt.second << ' ';
    }
    

    return 0;
}