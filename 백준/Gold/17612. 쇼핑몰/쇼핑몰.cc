#include <bits/stdc++.h>
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
using namespace std;
priority_queue<int, vector<int>, greater<int>> cart;
struct node
{
    int time, cart, id;
    bool operator<(const node &a) const
    {
        if (a.time == time)
            return a.cart < cart;
        return a.time < time;
    }
};
bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return b[1] < a[1];
    else
        return a[0] < b[0];
}

int n, k;
priority_queue<node> pq;

int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cart.push(i);
    }
    long long answer = 0;
    vector<vector<int>> arr;

    for (int i = 1; i <= n; i++)
    {
        int id, t;
        cin >> id >> t;
        if (pq.size() < k)
        {
            int cur = cart.top();
            cart.pop();
            pq.push({t, cur, id});
        }
        else
        {
            auto cur = pq.top();
            pq.pop();
            arr.push_back({cur.time, cur.cart, cur.id});
            pq.push({cur.time + t, cur.cart, id});
        }
    }
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        arr.push_back({cur.time, cur.cart, cur.id});
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        answer += (long long)(i + 1) * arr[i][2];
    }
    cout << answer;

    return 0;
}