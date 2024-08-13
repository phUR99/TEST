#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int T, N, K;
int arr[10005];

int main(){
    fastio;

    cin >> T;
    for (int test_Case = 1; test_Case <= T; test_Case++)
    {
        cin >> N >> K;
        int idx = 0;
        int tmp;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < N; i++)
        {
            cin >> tmp;
            if(tmp > arr[idx]){
                idx++;
                arr[idx] = tmp;
            }
            else{
                int cur_idx = lower_bound(arr, arr+idx+1, tmp) - arr;
                arr[cur_idx] = tmp;
            }
        }
        cout << "Case #" << test_Case << '\n';
        if(idx >= K) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    

    return 0;
}