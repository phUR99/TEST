#include <bits/stdc++.h>
using namespace std;

#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL)
int N;

int main()
{
    fastio;
    int answer = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        pq.push(t);
    }
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        if (cur > answer)
            break;
        answer += cur;
    }
    cout << answer;

    return 0;
}