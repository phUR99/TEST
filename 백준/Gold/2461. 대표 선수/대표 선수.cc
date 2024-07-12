#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M;
int idx[1005];
int board[1005][1005];

int main(){
    fastio;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }        
    }
    for (int i = 0; i < N; i++)
    {
        sort(board[i], board[i]+M);
    }
    

    int ans = 0x7fffffff;

    while (true)
    {
        int minValue = 0x7fffffff;
        int maxValue = 0;
        int minIdx = 0;
        for (int i = 0; i < N; i++)
        {
            if(board[i][idx[i]] < minValue){
                minIdx = i;
                minValue = board[i][idx[i]];
            }
            if(board[i][idx[i]] > maxValue){
                maxValue = board[i][idx[i]];
            }
        }
        
        ans = min(ans, maxValue - minValue);
        idx[minIdx]++;
        if(idx[minIdx] == M) break;
    }
    cout << ans;

    return 0;
}