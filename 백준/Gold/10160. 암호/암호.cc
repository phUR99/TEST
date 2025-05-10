    #include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
ll mod = 1e9 + 9;
ll cache[1000005];

ll solve(int idx){
    if(idx == n) return 1;
    ll &ret = cache[idx];
    if(ret != -1) return ret;
    ret = 0;
    ret = (ret + solve(idx + 1) % mod * k) % mod;
    if (idx + 5 <= n)
        ret = (ret - solve(idx + 5) % mod * 2) % mod;
    if (idx + 7 <= n)
        ret = (ret + solve(idx + 7)) % mod;
    ret = (ret + mod) % mod;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    ll ret = solve(0);
    cout << ret;
    return 0;
}