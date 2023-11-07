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
int x[1'000'005];
int d[1'000'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    d[0] = x[0];
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        if (x[i] > d[last])
        {
            d[++last] = x[i];
        }
        else
        {
            int idx = lower_bound(d, d + last, x[i]) - d;
            d[idx] = x[i];
        }
    }
    cout << last + 1;
}