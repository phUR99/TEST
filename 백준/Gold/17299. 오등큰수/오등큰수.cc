#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
stack<int> s;
int arr[1000005], freq[1000005];
int n;

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    stack<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && freq[s.top()] <= freq[arr[i]])
        {
            s.pop();
        }
        if (s.empty())
            ans.push(-1);
        else
            ans.push(s.top());
        s.push(arr[i]);
    }
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}