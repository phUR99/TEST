#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int arr[100005];
int N;
int idx = 0;

int main(){
    fastio;
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if(tmp > arr[idx]){
            idx++;
            arr[idx] = tmp;
        }
        else{
            int pos = lower_bound(arr, arr+idx+1, tmp) - arr;
            arr[pos] = tmp;
        }
    }
    cout << N - idx;

    return 0;
}