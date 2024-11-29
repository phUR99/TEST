#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, k;
vector<int> arr;

int main()
{
    fastio;
    cin >> n >> k;
    arr.resize(n);
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    int total = arr.back() - arr.front();
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    priority_queue<int> pq;
    for (int i = 1; i < arr.size(); i++)
    {
        pq.push(arr[i] - arr[i - 1]);
    }
    k--;
    while (!pq.empty() && k--)
    {
        total -= pq.top();
        pq.pop();
    }
    cout << total;
    return 0;
}