#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, m;
int sum[11];
int main()
{
    fastio;
    cin >> n >> m;
    priority_queue<int> pq;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        int *idx = min_element(sum, sum + m);
        *idx += now;
    }
    cout << *max_element(sum, sum + m);

    return 0;
}