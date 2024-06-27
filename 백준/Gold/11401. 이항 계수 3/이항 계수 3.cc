#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long N, K, A, B;
/*
1. mod는 나눗셈 연산에서 적용 불가능
팩토리얼로 해결하는 방법 불가능
->
따라서 페르마의 소정리를 활용해서(N^(P-2) = N^-1 % P) 1 / K! % MOD 를 N^(MOD-2)를 이용해서 구하기
MOD가 매우 큰 값이므로(1e9) 따라서 분할정복을 이용해서 log의 시간복잡도로 구하기
*/
long long solution(int n){
    if(n == 0) return 1;

    if(n % 2 == 1) return B * solution(n-1) % MOD;
    else {
        long long half = solution(n/2);
        return half * half % MOD;
    }    
}


int main(){
    fastio;
    cin >> N >> K;
    A = 1;
    for (long long i = N; i > N-K; i--)
    {
        A = (A * i) % MOD;
    }
    B = 1;
    for (long long i = 1; i <= K; i++)
    {
        B = (B * i) % MOD;
    }
    
    B = solution(MOD-2);    
    cout << A * B % MOD;
    return 0;

}