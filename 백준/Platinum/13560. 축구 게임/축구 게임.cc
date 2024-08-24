#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)

int main()
{
    fastio;

    int N;
    cin >> N;
    vector<int> arr;
    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum < i * (i + 1) / 2)
        {
            cout << -1;
            return 0;
        }
    }
    if (sum != N * (N - 1) / 2)
    {
        cout << -1;
        return 0;
    }
    cout << 1;
    return 0;
}