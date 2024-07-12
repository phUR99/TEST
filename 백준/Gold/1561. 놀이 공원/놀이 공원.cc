#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long N, M;
long long arr[10005];



int main(){
    fastio;
    cin >> N >> M;    

    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    if(N <= M) {
        cout << N;
        return 0;
    }
    long long st = 0; long long ed = 60000000000;

    while (st <= ed)
    {
        long long mid = (st + ed) / 2;
        long long sum = 0;
        for (int i = 0; i < M; i++)
        {
            sum += mid / arr[i] + 1;
        }
        if(sum >= N){
            ed = mid - 1;
        }
        else st = mid + 1;        
    }
    long long S = 0;
    for (int i = 0; i < M; i++)
    {
        S += (st - 1) / arr[i] + 1;
    }
    for (int i = 0; i < M; i++)
    {
        if(st % arr[i] == 0) S++;
        if(S != N) continue;
        cout << i + 1;
        break;
    }        

    return 0;
}