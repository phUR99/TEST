#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
ll arr[100005];

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll sum = accumulate(arr, arr + n, -arr[n - 1]);
    int M = arr[n - 1];
    if (M > sum)
        cout << M - sum;
    else if (M == sum)
        cout << 0;
    else
        cout << ((M + sum) % 2 ? 1 : 0);
    return 0;
}