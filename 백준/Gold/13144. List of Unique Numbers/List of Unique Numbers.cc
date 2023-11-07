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
int x[100'005];
bool cnt[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int ed = 0;
    ll ans = 0;
    cnt[x[ed]] = true;
    for (int st = 0; st < n; st++)
    {
        while (ed + 1 != n && !cnt[x[ed + 1]]) {
            ed++;
            cnt[x[ed]] = true;
            ans += ed - st + 1;
        }        
        cnt[x[st]] = false;
        
    }
    cout << ans + 1;
}