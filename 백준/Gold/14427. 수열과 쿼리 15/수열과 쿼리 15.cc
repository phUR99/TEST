#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int arr[100005];
int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push({arr[i], i});
    }
    int m;
    cin >> m;
    while (m--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int i, v;
            cin >> i >> v;
            arr[i] = v;
            pq.push({v, i});
        }
        else
        {
            int idx, val;
            while (1)
            {
                idx = pq.top().second;
                val = pq.top().first;
                if (val == arr[idx])
                    break;
                pq.pop();
            }
            cout << idx << '\n';
        }
    }

    return 0;
}