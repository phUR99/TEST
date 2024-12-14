#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, h, t;

int main()
{
    fastio;
    cin >> n >> h >> t;
    int c = t;
    priority_queue<int> pq;
    while (n--)
    {
        int height;
        cin >> height;
        pq.push(height);
    }
    while (c--)
    {
        if (pq.top() < h || pq.top() == 1)
            break;
        pq.push(pq.top() / 2);
        pq.pop();
    }
    c++;
    if (pq.top() >= h)
    {
        cout << "NO\n";
        cout << pq.top();
    }
    else
    {
        cout << "YES\n";
        cout << t - c;
    }

    return 0;
}