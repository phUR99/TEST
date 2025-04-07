#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
char board[55][55];
int solve(){
    char now = 'm';
    int cnt = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (now != board[i][j])
            {
                ret = max(ret, cnt);
                cnt = 1;
                now = board[i][j];
            }
            else{
                cnt++;
            }
        }
        ret = max(ret, cnt);
    }
    now = 'm';
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (now != board[j][i])
            {
                ret = max(ret, cnt);
                cnt = 1;
                now = board[j][i];
            }
            else
                cnt++;
            
        }
        ret = max(ret, cnt);
    }
 
    return ret;
    
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];    
        }
        
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (board[i][j] == board[i][j+1])
                continue;
            swap(board[i][j], board[i][j+1]);
            ret = max(solve(), ret);
            swap(board[i][j], board[i][j+1]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (board[j][i] == board[j+1][i])
                continue;
            
            swap(board[j][i], board[j+1][i]);
            ret = max(solve(), ret);
            swap(board[j][i], board[j+1][i]);
        }
        
    }
    
    cout << ret;
    
    return 0;
}