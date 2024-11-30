#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;
    int st = 301, ed = 1130;
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int ma, da, mb, db;
        cin >> ma >> da >> mb >> db;
        arr[i] = {ma * 100 + da, mb * 100 + db};
    }
    sort(arr.begin(), arr.end());
    priority_queue<int> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (st > ed)
            break;
        int a = arr[i].first;
        int b = arr[i].second;
        if (a > st)
        {
            if (pq.empty() || pq.top() < a)
                break;
            st = pq.top();
            cnt++;
        }
        pq.push(b);
    }
    if (!pq.empty() && st <= ed)
    {
        cnt++;
        st = pq.top();
    }

    if (st > ed)
        cout << cnt;
    else
        cout << 0;
    return 0;
}