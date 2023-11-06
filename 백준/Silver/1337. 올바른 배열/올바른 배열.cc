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
int x[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    
    int ans = 60; 
    sort(x, x + n);

    for (int st = 0; st < n; st++)
    {
        int cnt = 5;
        int ed = x[st];
        while (ed - x[st] <5)
        {
            if (binary_search(x, x + n, ed)) cnt--;
            ed++;
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}