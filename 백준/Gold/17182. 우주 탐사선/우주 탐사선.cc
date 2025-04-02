#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;

int full_bit;
int cache[10][1<<10];
int dist[10][10];

int solve(int st, int state){
    if(state == full_bit) return 0;
    int &ret = cache[st][state];
    if(ret != -1) return ret;

    ret = 987654321;
    for (int i = 0; i < n; i++)
    {
        if(state & (1<< i)) continue;
        int nxtState = state | (1<<i);
        ret = min(ret, dist[st][i] + solve(i, nxtState));
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> k;

    full_bit = (1<<n)-1;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
        
    }
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
            }
            
        }
        
    }
    
    

    int ret = solve(k, (1 << k));
    cout << ret;
    return 0;
}