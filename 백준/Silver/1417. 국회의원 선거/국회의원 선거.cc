#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int cur;
int main()
{
    fastio;
    cin >> n;
    cin >> cur;
    int o = cur;
    priority_queue<int> pq;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    while (!pq.empty() && pq.top() >= cur)
    {
        int now = pq.top();
        pq.pop();
        now--;
        cur++;
        if (now != 0)
            pq.push(now);
    }
    cout << cur - o;

    return 0;
}