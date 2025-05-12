#include <bits/stdc++.h>
using namespace std;
int n, m, p;

#define ll long long
ll cache[105][105];
const ll mod = 1e9 + 7;

ll solve(int len, int remain){
    
    if (len == 0) return remain == 0;

    ll &ret = cache[len][remain];
    if (ret != -1) return ret;
    ret = 0;
    if (remain > 0)
        ret = (remain * solve(len - 1, remain - 1));

    if (n - remain > m) ret += solve(len -1, remain) * (n - remain - m);

    return ret %= mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> p;
    auto ret = solve(p, n);
    cout << ret;
    return 0;
}