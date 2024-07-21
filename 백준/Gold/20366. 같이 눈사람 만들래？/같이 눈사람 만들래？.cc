#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
int arr[605];

int main(){
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int ans = 0x7fffffff;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 3; j < n; j++)
        {
            int i1 = i + 1, j1 = j - 1;
            while (i1 < j1)
            {
                ans = min(ans, abs(arr[i]+arr[j] - arr[j1]-arr[i1]));
                if(arr[i]+arr[j] <= arr[i1]+arr[j1]) j1--;
                else i1++;
            }
            
        }        
    }    
    
    cout << ans;

    return 0;
}