#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n = 11;
bitset<12> board[12], tmp[12];
void init(){
    for (int i = 1; i < n; i++)
    {
        tmp[i] = board[i];
    }
    return;
}

int solve(int start){
    int ret = 0;
    int state = start;
    init();

    for (int i = 0; i < 10; i++)
    {
        if(state & (1<< i)){
            // tmp[i] ^= (1<< i);
            tmp[0].flip(i+1);
            tmp[1].flip(i);
            tmp[1].flip(i+1);
            tmp[1].flip(i+2);
            tmp[2].flip(i+1);
            ret++;
        }
    }
    

    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(tmp[i-1][j]){
                tmp[i-1].flip(j);
                tmp[i].flip(j-1);
                tmp[i].flip(j);
                tmp[i].flip(j+1);
                tmp[i+1].flip(j);
                ret++;
            }
        }
    }

    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(tmp[i][j]) return 987654321;
        }
        
    }
    return ret;
}

int main()
{
    fastio;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            char c;
            cin >> c;
            if(c == 'O')
                board[i].set(j);
        }
    }
    int full_bit = (1<<10)-1;
    int ret = 987654321;

    for (int state = full_bit; state >= 0; state--)
    {
        ret = min(ret , solve(state));
    }
    if(ret == 987654321) ret = -1;
    cout << ret;
    
    return 0;
}