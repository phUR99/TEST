#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int child[300005];
int K;
int n;

int main()
{
    fastio;
    cin >> n >> K;
    for (int i = 0; i < n; i++)
    {
        cin >> child[i];
    }
    priority_queue<int> pq;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        pq.push(child[i] - child[i - 1]);
    }
    K--;
    int sum = child[n - 1] - child[0];
    while (K--)
    {
        sum -= pq.top();
        pq.pop();
    }
    cout << sum;

    return 0;
}