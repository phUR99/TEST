#include <bits/stdc++.h>

using namespace std;
#define ll long long
int arr[50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) cout << -1 << '\n';
            else {
                cout << pq.top() << '\n'; 
                pq.pop();
            }
        }
        else
        {
            while (num--)
            {
                int temp;
                cin >> temp;
                pq.push(temp);
            }           
        }
    }
}