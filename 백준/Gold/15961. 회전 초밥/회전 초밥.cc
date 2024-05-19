#include <bits/stdc++.h>
using namespace std;

int N, d, k, c;
int arr[3000000 + 3000 + 50];
int kind[3050];
int sum = 1, ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> N >> d >> k >> c;
    kind[c]++;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = N; i < N + k; i++)
    {
        arr[i] = arr[i-N];
    }
    for (int i = 0; i < k; i++)
    {
        if (kind[arr[i]] == 0) {
            sum++;
        }
        kind[arr[i]]++;
    }
    ans = max(ans, sum);

    for (int i = k; i < N+k; i++)
    {
        if (kind[arr[i]] == 0) sum++;            
        kind[arr[i]]++;
        int end = i - k;
        kind[arr[end]]--;
        if(kind[arr[end]] == 0) sum--;
        ans = max(ans, sum);
    }
    cout << ans;
    

    


    return 0;
}