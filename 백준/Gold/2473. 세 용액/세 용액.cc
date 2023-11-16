#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll arr[5'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll sum = 3e9 + 1;
    int ans1, ans2, ans3;
    for (int i = 0; i < n-2; i++)
    {
        int st = i + 1;
        int ed = n - 1;
        while (st < ed)
        {
            if (abs(arr[i] + arr[st] + arr[ed]) < sum) {
                sum = abs(arr[i] + arr[st] + arr[ed]);
                ans1 = arr[i];
                ans2 = arr[st];
                ans3 = arr[ed];
            }
            if (arr[i] + arr[st] + arr[ed] > 0) ed--;
            else st++;
            
        }
    }
    cout << ans1 << ' ' << ans2 << ' ' << ans3;

}