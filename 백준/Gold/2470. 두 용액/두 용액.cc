#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int st = 0; int ed = n - 1;
    int ans1, ans2;
    int dif = 2e9 + 1;
    while (st < ed)
    {
        if (abs(arr[st]+arr[ed]) < dif)
        {
            dif = abs(arr[st] + arr[ed]);
            ans1 = arr[st];
            ans2 = arr[ed];
        }
        if (arr[st] + arr[ed] > 0) ed--;
        else st++;
        
    }
    cout << ans1 << ' ' << ans2;
}