#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, r, l, x;
int solve(int state);
int arr[20];
int solve(int state)
{
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
            tmp.push_back(arr[i]);
    }
    sort(tmp.begin(), tmp.end());
    int sum = accumulate(tmp.begin(), tmp.end(), 0);
    int diff = tmp.back() - tmp.front();
    return l <= sum && sum <= r && diff >= x;
}

int main()
{
    fastio;
    cin >> n >> l >> r >> x;
    int full_bit = (1 << n) - 1;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int state = full_bit; state; state--)
    {
        if (__builtin_popcount(state) <= 1)
            continue;
        ret += solve(state);
    }
    cout << ret;
    return 0;
}