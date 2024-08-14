#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int N;
int arr[1005];
int cache[1005];

int main(){
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int M, m;

    for (int i = 0; i < N; i++)
    {
        M = arr[i];
        m = arr[i];
        for (int j = i; j >= 0; j--)
        {
            M = max(M, arr[j]);
            m = min(m, arr[j]);
            cache[i+1] = max(cache[i+1], cache[j] + M - m);
        }
        
    }
    cout << cache[N];
    

    return 0;
}