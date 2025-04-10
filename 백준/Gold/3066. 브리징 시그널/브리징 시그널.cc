#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[40005];
int cur[40005];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(cur, 0, sizeof(cur));
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > cur[idx]){
            cur[++idx] = arr[i];
        }
        else{
            int new_idx = lower_bound(cur, cur+idx+1, arr[i]) - cur;
            cur[new_idx] = arr[i];
        }
    }
    cout << idx <<'\n';
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}