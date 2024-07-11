#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long N, K;
long long count(long long x){
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += min(x/i, N);
    }
    return sum;    
}

int main(){
    fastio;
    cin >> N >> K;
    long long low = 1;
    long long high = N * N;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long cnt = count(mid);
        if(cnt >= K) high = mid - 1;
        else low = mid + 1;
    }
    cout << low;    



    return 0;
}