#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
int n;
int color[200005];
int ssize[200005];
vector<vector<int>> colorPrefix, colorSort;
vector<int> sortedArray;
int prefix[200005];

int main()
{
    fastio;
    cin >> n;
    colorPrefix.resize(n + 1);
    colorSort.resize(n + 1);
    sortedArray.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> color[i] >> ssize[i];
        sortedArray[i] = ssize[i];
        colorSort[color[i]].push_back(ssize[i]);
    }
    sort(sortedArray.begin(), sortedArray.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix[i] = sortedArray[i] + sum;
        sum += sortedArray[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        sort(colorSort[i].begin(), colorSort[i].end());
        for (auto node : colorSort[i])
        {
            colorPrefix[i].push_back(sum + node);
            sum += node;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(sortedArray.begin(), sortedArray.end(), ssize[i]) - sortedArray.begin();
        int total = (idx == 0) ? 0 : prefix[idx - 1];
        idx = lower_bound(colorSort[color[i]].begin(), colorSort[color[i]].end(), ssize[i]) - colorSort[color[i]].begin();
        int minus = (idx == 0) ? 0 : colorPrefix[color[i]][idx - 1];
        cout << total - minus << '\n';
    }

    return 0;
}