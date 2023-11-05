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
int n, k;
int x[100'005];
int sum[100'005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        c += x[i];
        sum[i] = c;

    }
    int ans = -0x7fffffff;
    for (int i = k; i <= n; i++)
    {
        ans = max(ans, sum[i] - sum[i - k]);
    }
    cout << ans;
}