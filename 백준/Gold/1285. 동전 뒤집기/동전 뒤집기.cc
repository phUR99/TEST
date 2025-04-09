#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int full_bit = 0;
array<int, 20> init;
int n;
int solve(array<int, 20> &cur, int state){
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if(state & (1<< i)) cur[i] = ~cur[i];
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(cur[j] & (1<<i)) cnt++;
        }
        ret += max(cnt, n-cnt);   
        //cout << ret << ' ';
    }
    return ret;
}
int main()
{
    fastio;

    cin >> n;
    full_bit = (1<<n)-1;
    for (int i = 0; i < n; i++)
    {
        int row = 0;
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if(c == 'H') row |= (1 << j);

        }
        init[i] = row;
        //cout << row << '\n';
    }
    int ret = 0;
    for (int state = full_bit; state >= 0; state--)
    {
        array<int, 20> tmp = init;
        ret = max(ret, solve(tmp, state));
    }
    cout << n*n-ret;
    
    return 0;
}