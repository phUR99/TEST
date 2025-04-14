#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[2500][2500];
int n;
int cache[2500][2500];

int solve(int x, int y){
    if(x == n -1 && y == n -1) return 0;
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 987654321;
    if(x != n - 1)
        ret = min(ret, solve(x+1, y) + max(0, arr[x+1][y]+1 - arr[x][y]));
    if(y != n - 1)
        ret = min(ret, solve(x, y+1) + max(0, arr[x][y+1]+1 - arr[x][y]));
    return ret;
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}