#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cache[25][25][25];
int n, l, r;

ll caching(int cur, int left, int right){
    if (cur == n)
        return left == l && right == r;
    
    ll &ret = cache[cur][left][right];
    if (ret != -1) return ret;
    ret = 0;
    ret += caching(cur+1, left+1, right);
    ret += caching(cur+1, left, right+1);
    ret += caching(cur+1, left, right) * (cur -1);
    return ret;
}

void solve(){
    cin >> n >> l >> r;
    cout << caching(1, 1, 1) << '\n';
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(cache, -1, sizeof(cache));
        solve();
    }
    

    return 0;
}