#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <tuple>
#include <numeric>

using namespace std;
#define ll long long


int n;
int a[4005], b[4005], c[4005], d[4005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> ab, cd;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());
    
    ll ans = 0;
    for (auto i : ab)
    {
        if (binary_search(cd.begin(), cd.end(), -i)) {
            auto idx_l = lower_bound(cd.begin(), cd.end(), -i);
            auto idx_u = upper_bound(cd.begin(), cd.end(), -i);
            ans += idx_u - idx_l;
        }
    }
    cout << ans;
  
}