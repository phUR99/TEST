#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
array<int, 4> goal;
vector<array<int, 5>> arr;
int n;

int solve(int state)
{
    int ret = 0;
    array<int, 5> cmp;
    cmp.fill(0);
    for (int i = 0; i < n; i++)
    {
        if (state & (1 << i))
        {
            for (int j = 0; j < 5; j++)
            {
                cmp[j] += arr[i][j];
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cmp[i] -= goal[i];
    }
    if (*min_element(cmp.begin(), cmp.begin() + 4) >= 0)
        return cmp[4];

    return 987654321;
}

int main()
{
    fastio;

    cin >> n;
    arr.resize(n);
    for (auto &i : goal)
    {
        cin >> i;
    }
    for (auto &e : arr)
    {
        for (auto &i : e)
        {
            cin >> i;
        }
    }
    vector<vector<int>> ans;
    int full_bit = (1 << n) - 1;
    int ret = 987654321;

    for (int state = full_bit; state >= 0; state--)
    {
        int v = solve(state);
        if (v == ret)
        {

            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                if (state & (1 << i))
                    tmp.push_back(i + 1);
            }
            ans.push_back(tmp);
        }
        else if (v < ret)
        {
            ret = v;
            ans.clear();
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                if (state & (1 << i))
                    tmp.push_back(i + 1);
            }
            ans.push_back(tmp);
        }
    }
    if (ret == 987654321)
    {
        cout << -1;
    }
    else
    {
        sort(ans.begin(), ans.end());
        cout << ret << '\n';
        for (auto c : ans[0])
        {
            cout << c << ' ';
        }
    }
    return 0;
}