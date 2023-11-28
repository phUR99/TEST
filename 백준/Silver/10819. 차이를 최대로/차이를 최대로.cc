#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n;
int ans = 0;
int arr[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    do
    {
        int tmp = 0;
        for (int i = 1; i < n; i++)
        {
            tmp += abs(arr[i] - arr[i - 1]);
        }
        ans = max(ans, tmp);
    } while (next_permutation(arr, arr+n));
    cout << ans;
}