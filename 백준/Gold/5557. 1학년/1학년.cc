#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
long long cache[105][25];
int arr[105];
int N;


int main(){
    fastio;

    cin >> N;
    memset(cache, 0, sizeof(cache));

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cache[1][arr[1]] = 1;
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if(j - arr[i] >= 0) cache[i][j-arr[i]] += cache[i-1][j];
            if(j + arr[i] <= 20) cache[i][j+arr[i]] += cache[i-1][j];
        }
        
    }
    
    long long answer = cache[N-1][arr[N]];
    cout << answer;
    return 0;
}