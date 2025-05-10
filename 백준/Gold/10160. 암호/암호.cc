#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
ll mod = 1e9 + 9;
ll cache[1000005][5][2];

ll solve(int idx, int state, int third){
    if(idx == n) return 1;
    ll &ret = cache[idx][state][third];
    if(ret != -1) return ret;
    ret = 0;
    switch (state)
    {
    case 0:
        ret += solve(idx+ 1, 0, 0) * (k - 1);
        ret += solve(idx+ 1, 1, 0);
        break;
    case 1:
        ret += solve(idx + 1, 0, 0) * (k - 2);
        ret += solve(idx + 1, 1, 0);
        ret += solve(idx + 1, 2, 0);   
        break;
    case 2:
        ret += solve(idx + 1, 0, 0) * (k - 2);
        ret += solve(idx + 1, 3, 0);
        ret += solve(idx + 1, 3, 1);
        break;
    case 3:
        ret += solve(idx + 1, 0, third) * (k - 2);
        ret += solve(idx + 1, 1, third);
        ret += solve(idx + 1, 4, third);
        break;
    case 4:
        if (third)
            ret += solve(idx +1, 3, third);
        else    
            ret += solve(idx +1, 1, 0);
        ret += solve(idx + 1, 0, 0) * (k - 2);
        break;
    }
    ret %= mod;
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    ll ret = solve(0, 0, 0);
    cout << ret;
    return 0;
}