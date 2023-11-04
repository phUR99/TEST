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
int n, budget;
int x[200'005];

bool solve(int cur) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(cur, x[i]);
    }
    return budget >= sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cin >> budget;
    sort(x, x + n);
    int st = 1; int ed = x[n - 1];
    while (st < ed)
    {
        int mid = (st + ed + 1) / 2;
        if (solve(mid)) st = mid;
        else ed = mid - 1;
    }
    cout << st;
}