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
int x[200'005];

bool solve(int cur) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += x[i] / cur;
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];

    }
    ll st = 0; ll ed = *max_element(x, x + n);
    while (st < ed)
    {
        ll mid = (st + ed + 1) / 2;
        if (solve(mid)) st = mid;
        else ed = mid - 1;
        
    }
    cout << st;
}