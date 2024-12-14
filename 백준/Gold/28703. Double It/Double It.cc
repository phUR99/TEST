#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;

int main()
{
    fastio;
    int M = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        M = max(M, tmp);
        pq.push(tmp);
    }
    int l = M;
    int diff = 1e9 + 1;
    while (pq.top() <= l)
    {
        int m = pq.top();
        pq.pop();
        // cout << m << ' ' << M << '\n';
        diff = min(diff, abs(M - m));
        pq.push(2 * m);
        M = max(2 * m, M);
    }
    cout << diff;
    return 0;
}