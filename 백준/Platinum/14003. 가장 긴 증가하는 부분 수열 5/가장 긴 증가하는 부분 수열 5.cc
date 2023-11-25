#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a[1'000'005];
int h[1'000'005], o[1'000'005];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(h, h + n, 1e9+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[idx] < a[i]) {
            idx++;
            h[idx] = a[i];
            o[i] = idx;
        }
        else
        {
            auto l = lower_bound(h, h + n, a[i]) - h;
            h[l] = a[i];
            o[i] = l;
        }
    }
    vector<int> answer;
    int cur = idx;
    for (int i = n-1; i >= 0; i--)
    {
        if (o[i] == cur) {
            answer.push_back(a[i]);
            cur--;
        }
    }
    cout << idx + 1 << '\n';
    reverse(answer.begin(), answer.end());
    for (auto e : answer)
    {
        cout << e << ' ';
    }
}