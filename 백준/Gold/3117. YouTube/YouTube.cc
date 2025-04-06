#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[100005];
int nxt[30][100005];
int n, k, m;

void solve(int start){
    for (int i = 0; i < 30; i++)
    {
        if(m &(1<<i))
            start = nxt[i][start];
    }
    
    cout << start << ' ';
}

int main()
{
    fastio;
    cin >> n >> k >> m;
    m--;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    
    for (int i = 1; i <= k; i++)
    {
        cin >> nxt[0][i];
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 1; i <= k; i++)
        {
            nxt[j][i] = nxt[j-1][nxt[j-1][i]];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        solve(arr[i]);
    }
    
    
    
    return 0;
}