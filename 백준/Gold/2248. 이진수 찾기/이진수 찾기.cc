#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, l;
unsigned int i;
int cache[35][35];
int solve(int idx, int remain){
    if(idx == n) return cache[idx][remain] = 1;
    int &ret = cache[idx][remain];
    if(ret != -1) return ret;
    ret = 0;
    if(remain)
        ret += solve(idx+1, remain-1);
    ret += solve(idx+1, remain);
    return ret;
}
string trace(int idx, int ones, unsigned int order){
    if(idx == n) return string();
    const int &cur = cache[idx+1][ones];
    //cout << cur << ' ' << order << '\n';
    if(order < cur)
        return string("0") + trace(idx+1, ones, order);
    else
        return string("1") + trace(idx+1, ones-1, order - cur);
}
int main()
{
    fastio;
    cin >> n >> l >> i;
    memset(cache, -1, sizeof(cache));
    solve(0, l);
    string ret = trace(0, l, i-1);
    cout << ret;
    return 0;
}