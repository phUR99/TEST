#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long

int main()
{
    fastio;

    int m;
    cin >> m;
    vector<pair<int, int>> arr;
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        if (b <= a)
            continue;
        arr.push_back({a, -b});
    }
    sort(arr.begin(), arr.end());
    int st = 0;
    int cnt = 0;
    auto iter = arr.begin();
    priority_queue<int> pq;
    while (st < m)
    {
        int max_end = st;
        while (iter != arr.end() && iter->first <= st)
        {
            max_end = max(max_end, -iter->second);
            iter++;
        }
        if (max_end == st)
        {
            cout << 0;
            return 0;
        }
        st = max_end;
        cnt++;
    }
    cout << cnt;
    return 0;
}