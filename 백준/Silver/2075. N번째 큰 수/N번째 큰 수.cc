#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        int x;
        cin >> x;
        if (pq.size() < n) pq.push(x);
        else
        {
            if (x > pq.top())
            {
                pq.push(x);
                pq.pop();
            }
        }
    }
    cout << pq.top();
}