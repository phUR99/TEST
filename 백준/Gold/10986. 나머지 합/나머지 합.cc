#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, M;
int pSum[1000005];
long long idx[1000];

int main(){
    fastio;
    cin >> N >> M;
    int cur;
    idx[0]++;

    for (int i = 1; i <= N; i++)
    {   
        cin >> cur;        
        pSum[i] = (pSum[i-1] + cur) % M;
        idx[pSum[i]]++;
    }
    long long answer = 0;

    for (int i = 0; i < M; i++)
    {
        answer += max(0LL, idx[i] * (idx[i]-1)/2);
    }
    cout << answer;

    return 0;
}