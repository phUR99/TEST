#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 21, 30, 31, 32, 40, 41, 42, 43, 50, 51, 52, 53, 54
int n;
vector<ll> arr;
void solve(int idx, int now, ll val){
    if(idx == 0){
        arr.push_back(val);
        return;
    }
    for (int i = 0; i < now; i++)
    {
        solve(idx-1, i, val*10+i);
    }
    
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i <= 10; i++)
    {
        solve(i+1, 10, 0);
    }
    sort(arr.begin(), arr.end());
    if(n >= arr.size()){
        cout << -1;
        return 0;
    }
    cout << arr[n];
    
    
    return 0;
}