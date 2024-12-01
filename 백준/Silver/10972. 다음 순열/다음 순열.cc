#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    if (next_permutation(arr.begin(), arr.end()))
    {
        for (auto &i : arr)
        {
            cout << i << ' ';
        }
    }
    else
        cout << -1;

    return 0;
}