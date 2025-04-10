#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr(10);
        for (auto &i : arr)
        {
            cin >> i;        
        }
        sort(arr.begin(), arr.end(), greater<>());
        cout << arr[2] << '\n';
    }
    
    return 0;
}