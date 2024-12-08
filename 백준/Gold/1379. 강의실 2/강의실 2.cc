#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
vector<int> number;
int main()
{
    fastio;
    int n;
    cin >> n;
    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][2] >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end());
    number.resize(n + 1);
    int M = 0;
    priority_queue<int, vector<int>, greater<int>> order;
    for (int i = 1; i <= n + 1; i++)
    {
        order.push(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i][0];
        int r = arr[i][1];
        int idx = arr[i][2];
        while (!pq.empty() && pq.top().first <= l)
        {
            order.push(pq.top().second);
            pq.pop();
        }
        pq.push({r, order.top()});
        number[idx] = order.top();
        order.pop();
        M = max((int)pq.size(), M);
    }
    cout << M << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << number[i] << '\n';
    }

    return 0;
}