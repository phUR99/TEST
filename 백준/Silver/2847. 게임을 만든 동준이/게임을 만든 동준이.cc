#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
vector<int> arr;
int main()
{
    fastio;
    cin >> n;
    int ret = 0;
    arr = vector<int>(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            ret += arr[i] - arr[i + 1] + 1;
            arr[i] = arr[i + 1] - 1;
        }
    }
    cout << ret;
    return 0;
}