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
int n, m;
int x[15'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int st = 0;
    int ed = n - 1;
    sort(x, x + n);
    int ans = 0;
    while (st < ed)
    {
        if (x[st] + x[ed] > m) {
            ed--;
        }
        else
        {
            if (x[st] + x[ed] == m) ans++;
            st++;
        }
    }
    cout << ans;
}