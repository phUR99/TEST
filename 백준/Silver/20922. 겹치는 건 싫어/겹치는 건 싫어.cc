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
int list[100'005];
int x[200'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int ans = 0;
    int ed = 0;
    list[x[0]]++;
    for (int st = 0; st < n; st++)
    {
        while (ed < n -1 && list[x[ed+1]] < k)
        {
            ed++;
            list[x[ed]]++;                                                  
        }
        ans = max(ed-st+1, ans);
        list[x[st]]--;

    }
    cout << ans;
}