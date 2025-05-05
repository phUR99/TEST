#include<bits/stdc++.h>
using namespace std;
int cache[255][250 * 250 + 1];
int a[255], b[255];
int n;
int ans = 987654321;
int solve(int idx, int remain){
    if (idx == n)
        return 0;
    int &ret = cache[idx][remain];
    if (ret != -1)
        return ret;    
    ret = solve(idx + 1, remain) + b[idx];
    if (remain - a[idx] >= 0)
        ret = min(ret, solve(idx + 1, remain - a[idx]));    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    for (int i = 0; i <= sum; i++)
    {
        ans = min(ans, max(i, solve(0, i)));
    }
    cout << ans;

    return 0;
}