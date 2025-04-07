#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int f[20][200005];
int solve(int n, int x){
    for (int i = 0; i < 20; i++)
    {
        if (n & (1<<i))
        {
            x = f[i][x];       
        }
        
    }
    return x;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[0][i];
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[j][i] = f[j-1][f[j-1][i]];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n, x;
        cin >> n >> x;
        cout << solve(n, x) << '\n';
    }
    
    
    return 0;
}