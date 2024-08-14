#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1'000'000'000
int N;
long long cache[1000005];

long long solution(int cur){
    if(cur < 2) return 0;
    if(cur == 2) return 1;
    long long &ret = cache[cur];
    if(ret != -1) return ret;
    ret = 0;
    ret += (cur-1) * (solution(cur-1) + solution(cur-2));
    ret %= MOD;
    return ret;
}

int main(){
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N;
    int answer = solution(N);
    cout << answer;
    return 0;
}