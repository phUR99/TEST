#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[255555];
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        while (arr[i - 1] > arr[i])
        {
            arr[i] *= 2;
            cnt++;
        }
        // cout << cnt << ' ';
    }
    cout << cnt;

    return 0;
}