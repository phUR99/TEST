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
int x[200'005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n);
    int ed = 0;
    int ans = 0x7fffffff;
    for (int st = 0; st < n; st++)
    {
        while (ed < n && x[ed] - x[st] < m) ed++;
        if (ed == n) break;
        ans = min(ans, x[ed] - x[st]);
    }
    cout << ans;
}