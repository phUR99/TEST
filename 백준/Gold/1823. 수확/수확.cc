#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int cache[4005][2005];
int n;
int arr[2005];
int solve(int idx, int l){
    if (idx == n) return 0;

    int &ret = cache[idx][l];
    if (ret != -1)
        return ret;
    ret = 0;
    
    return ret = max(solve(idx+1, l+1) + (idx+1) * arr[l], solve(idx+1, l) + (idx+1) * arr[n-1-idx+l]);
        
}
int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ret = solve(0, 0);
    cout << ret;
    return 0;
}