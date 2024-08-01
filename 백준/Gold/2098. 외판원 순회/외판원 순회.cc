#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
int weight[20][20];
int dist[20][(1<<16)-1];
const int INF = 0x3fffffff;
int full_bit;

int dfs(int cur, int state){
    if(state == full_bit){
        if(weight[cur][0] == 0) return INF;
        else return weight[cur][0];
    }
    
    int &ret = dist[cur][state];
    if(ret != -1) return ret;

    ret = INF;
    for (int i = 0; i < N; i++)
    {
        
        int nxt = state | (1 << i);
        //&의 우선순위가 !=보다 낮음
        if(weight[cur][i] == 0 || (state & (1 << i)) != 0) continue;
        ret = min(ret, dfs(i, nxt) + weight[cur][i]);
    }
    return ret;
}

int main(){
    fastio;
    cin >> N;
    full_bit = (1 << N) -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> weight[i][j];
        }
        
    }
    memset(dist, -1, sizeof(dist));
    cout << dfs(0, 1);
    return 0;
}