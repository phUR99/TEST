#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n;
int full_bit;
int arr[25][25];

int solve(vector<int> &v)
{
    int ret = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            ret += arr[v[i]][v[j]] + arr[v[j]][v[i]];
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    full_bit = (1 << n) - 1;
    int ret = 987654321;
    vector<int> one, zero;
    for (int bit = full_bit; bit; bit--)
    {
        if (__builtin_popcount(bit) == n)
            continue;
        one.clear();
        zero.clear();
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
                one.push_back(i);
            else
                zero.push_back(i);
        }
        ret = min(ret, abs(solve(one) - solve(zero)));
    }
    cout << ret;
    return 0;
}