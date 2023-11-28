#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define X first
#define Y second

int l[250050];
vector<pair<int, int>> vec;

int height[250050];
int idx[250050];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first) {
        return  a.second > b.second;
    }
    else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    vec.push_back({ -0x7fffffff, n });
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        l[i] -= temp;
        vec.push_back({l[i], i});
    }
    sort(vec.begin(), vec.end(), cmp);
    int cur = 1e9 + 1;
    for (int i = 0; i <= n; i++)
    {
        height[i] = vec[i].first;
        cur = min(cur, vec[i].second);
        idx[i] = cur;
    }
    cin >> w;
    while (w--)
    {
        cin >> temp;
        int score = lower_bound(height, height + n + 1, temp) - height;
        cout << idx[score-1] << '\n';
    }

}