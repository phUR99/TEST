#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
long long cache[10005];
long long solve(int cur){    
    if(cur == 2 || cur == 0) return 1;
    long long &ret = cache[cur];
    if(ret != -1) return ret;
    ret = 0;
    for (int i = 2; i <= cur; i+=2)
    {
        ret += solve(cur - i) * solve(i - 2);
        ret %= 987654321;
    }
    return ret;
}
int main(){
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    long long answer = solve(N);
    cout << answer;
    return 0;
}