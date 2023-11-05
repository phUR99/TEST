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
int n, s;
int x[200'005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int ed = 0;
    int cur = x[0];
    int ans = 0x7fffffff;
    for (int st = 0; st < n; st++)
    {
        while (ed < n && cur < s) {            
            ed++;
            if (ed != n) cur += x[ed];
        }
        if (ed == n) break;        
        ans = min(ans, ed - st + 1);
        cur -= x[st];
    }
    if (ans == 0x7fffffff) cout << 0;
    else cout << ans;
}