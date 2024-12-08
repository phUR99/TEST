#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[200005];
int idx;
int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        if (arr[idx] < e)
            arr[++idx] = e;
        else
        {
            int tmp = lower_bound(arr, arr + idx, e) - arr;
            arr[tmp] = e;
        }
    }
    cout << n - idx;

    return 0;
}