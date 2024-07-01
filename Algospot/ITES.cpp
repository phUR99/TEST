#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct RNG{
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next(){
        unsigned ret = seed;
        seed = ((seed * 214013u) + 25531011u);
        return ret % 10000 + 1;
    }
};

int countRanges(int k, int n){
    RNG rng;
    queue<int> range;
    int ret = 0, rangeSum = 0;
    for (int i = 0; i < n; i++)
    {
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        while (rangeSum > k)
        {
            rangeSum -= range.front();
            range.pop();
        }
        if (rangeSum == k) ret++;        
    }
    return ret;
}


int T, N, K;
//1 << 32가 아니라 1LL << 32로 처리
const long long MOD = (1LL << 32);
int main(){
    fastio;

    cin >> T;
    while (T--)
    {
        cin >> K >> N;
        deque<long long> SIG;
        long long A = 1983;        
        long long sum = 0;

        int iter = 0, ans = 0;
        while (iter < N)
        {            
            if(sum <= K){
                if(sum == K) ans++;
                long long value = A % 10000 + 1;
                sum += value;
                SIG.push_back(value);                
                A = (A * 214013 + 2531011) % MOD;                     
                iter++;
            }
            else{
                while (!SIG.empty() && sum > K)
                {
                    long long front = SIG.front(); SIG.pop_front();
                    sum -= front;
                }                
            }            
        }
        cout << ans << '\n';
    }
    
    return 0;
}