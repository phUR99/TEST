#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<pair<int, int>> arr;
int n, m;
int main()
{
    fastio;
    cin >> n >> m;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i.second >> i.first;
        i.second = -i.second;
    }
    sort(arr.begin(), arr.end());
    int weight = 0;
    int sum = 0;
    int before = -1;
    for (int i = 0; i < n; i++)
    {
        if (weight < m)
        {
            if (before == arr[i].first)
                sum += arr[i].first;
            else
                before = sum = arr[i].first;
        }
        else
        {
            if ((before != arr[i].first) && (arr[i].first <= sum))
            {
                before = sum = arr[i].first;
            }
        }
        weight += -arr[i].second;
    }
    if (weight < m)
        cout << -1;
    else
        cout << sum;

    return 0;
}