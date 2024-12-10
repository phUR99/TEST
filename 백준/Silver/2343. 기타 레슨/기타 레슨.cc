#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int arr[100005];

bool solve(int x)
{
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > x)
        {
            sum = arr[i];
            cnt++;
        }
        else
            sum += arr[i];
    }
    return cnt < m;
}

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = *max_element(arr, arr + n);
    int r = 1e9 + 10;
    while (l <= r)
    {
        int x = (l + r) / 2;
        if (solve(x))
            r = x - 1;
        else
            l = x + 1;
    }
    cout << l;
    return 0;
}