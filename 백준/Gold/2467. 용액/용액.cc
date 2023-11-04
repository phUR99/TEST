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
int a[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    //순차탐색으로 진행했을 때 기댓값이 n^2이므로 n의 제한이 100000에서는 불가능하다. nlogn ~= 50000정도로 이분탐색을 이용해서 해결하는게 목표.
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans1 = 1e9 + 1;
    int ans2 = 1e9 + 1;
    for (int i = 0; i < n; i++) { 
        //lower bound의 특성을 활용해서 항상 더 작은 idx를 반환하는 것을 활용한다.
        int idx = lower_bound(a, a + n, -a[i]) - a; 
        
        if (idx + 1 < n && i != idx + 1 && abs(a[i] + a[idx + 1]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[idx + 1];
        }
        if (idx < n && i != idx && abs(a[i] + a[idx]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[idx];
        }
        if (idx != 0 && i != idx - 1 && abs(a[i] + a[idx - 1]) < abs(ans1 + ans2)) {
            ans1 = a[i];
            ans2 = a[idx - 1];
        }
    }
    if (ans1 > ans2) swap(ans1, ans2); 
    cout << ans1 << ' ' << ans2;
}
