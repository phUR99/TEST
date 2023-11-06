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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int st = 1;
    int ed = 1;
    int sum = 0;
    int ans = 0;
    while (st <= ed && ed <=n)
    {
        if (sum < n) sum += ed++;
        else {
            if (sum == n) ans++;
            sum -= st++;
        }
    }
    cout << ans + 1;

}