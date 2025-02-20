#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
int n, l, m;
vector<pair<int, int>> nets;
vector<pair<int, int>> fishes;
void makeNets()
{
    for (int row = 1; row * 2 < l; row++)
    {
        int col = (l - 2 * row) / 2;
        nets.push_back({row, col});
    }
}

int solve(int i, vector<pair<int, int>> &arr)
{
    int ret = 0;
    for (auto net : nets)
    {
        for (int r = net.first; r >= 0; r--)
        {

            int u = arr[i].first - r;
            int d = arr[i].first + net.first - r;
            if (u < 1 || d > n)
                continue;
            for (int c = net.second; c >= 0; c--)
            {
                int left = arr[i].second - c;
                int right = arr[i].second + net.second - c;
                if (left < 1 || right > n)
                    continue;
                int cnt = 0;
                for (int idx = 0; idx < m; idx++)
                {
                    int irow = arr[idx].first;
                    int icol = arr[idx].second;
                    if (irow >= u && irow <= d && icol >= left && icol <= right)
                        cnt++;
                }
                ret = max(ret, cnt);
            }
        }
    }
    return ret;
}

int main()
{
    fastio;
    cin >> n >> l >> m;
    makeNets();
    fishes.resize(m);
    for (auto &i : fishes)
    {
        cin >> i.first >> i.second;
    }
    sort(fishes.begin(), fishes.end());
    int ret = 0;
    for (int i = 0; i < m; i++)
    {
        ret = max(ret, solve(i, fishes));
    }
    cout << ret;
    return 0;
}