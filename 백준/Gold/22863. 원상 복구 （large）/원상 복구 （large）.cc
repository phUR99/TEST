#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int sparse[50][1000005];
int arr[1000005];
int ret[1000005];

ll n, k;
int s;

int main()
{
    fastio;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> sparse[0][i];
    }
    for (int j = 1; j < 50; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            sparse[j][i] = sparse[j-1][sparse[j-1][i]];
        }        
    }
    for (int i = 1; i <= n; i++)
    {
        ll v = k;
        int start = i;
        for (int i = 49; i >= 0; i--)
        {
            if(v &(1LL<<i))
                start = sparse[i][start];
        }
        ret[start] = arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ret[i] << ' ';
    }
    
    
    

    
    return 0;
}