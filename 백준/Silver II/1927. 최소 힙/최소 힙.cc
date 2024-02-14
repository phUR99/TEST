#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (!min_heap.empty() && n == 0)
        {
            cout << min_heap.top() << '\n';
            min_heap.pop();
        }
        else if (min_heap.empty() && n == 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            min_heap.push(n);
        }
    }

}